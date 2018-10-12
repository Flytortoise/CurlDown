#include "mycurldown.h"
#include "curl/curl.h"
#include <sys/stat.h>
#include <QDebug>
#include "curldownelement.h"

CurlDown::CurlDown(CurlDownElement *curl)
{
    m_curldownelement = curl;
    m_curl = curl_easy_init();
    curl_easy_setopt(m_curl, CURLOPT_WRITEFUNCTION, wirtefunc);
    curl_easy_setopt(m_curl, CURLOPT_WRITEDATA, this);

    m_File = nullptr;

    m_runflag = STOP;
    m_pos = 0;
}

CurlDown::~CurlDown()
{
    this->Stop();
}

bool CurlDown::SetFileName(QString FileName)
{
    if(m_File){
        fclose(m_File);
    }

    struct stat file_info;
    if(stat(FileName.toStdString().c_str(), &file_info) == 0){  //文件存在，说明已经被下载过
        SetResumeFormLarge(file_info.st_size);
    }

    m_File = fopen(FileName.toStdString().c_str(), "ab+");
    return m_File != nullptr;
}

bool CurlDown::SetResumeForm(long pos)
{
    if(pos <= 0 )
        return false;

    m_pos = pos;
    CURLcode res = curl_easy_setopt(m_curl, CURLOPT_RESUME_FROM, pos);
    return res == CURLE_OK;
}

bool CurlDown::SetResumeFormLarge(long long pos)
{
    if(pos <= 0 )
        return false;

    m_pos = pos;
    CURLcode res = curl_easy_setopt(m_curl, CURLOPT_RESUME_FROM_LARGE, pos);
    return res == CURLE_OK;
}

void CurlDown::Pause()
{
    if(m_runflag == RUN){
        curl_easy_pause(m_curl,CURLPAUSE_ALL);
        m_runflag = PAUSE;
    }
    else if(m_runflag == PAUSE){
        curl_easy_pause(m_curl,CURLPAUSE_CONT);
        m_runflag = RUN;
    }
}

void CurlDown::Stop()
{
    if(m_runflag == STOP)
        return;

    m_runflag = STOP;

    if(m_File){
        fclose(m_File);
        m_File = nullptr;
    }

    if(m_curl){
        curl_easy_cleanup(m_curl);
        m_curl = nullptr;
    }
}

bool CurlDown::SetTimeOut(int timeout)
{
    if(timeout < 0)
        return false;

    CURLcode res = curl_easy_setopt(m_curl, CURLOPT_CONNECTTIMEOUT, timeout);
    return res == CURLE_OK;
}

bool CurlDown::DownFile(QString FileName, QString URL)
{
    this->SetFileName(FileName);


    CURLcode res = CURLE_GOT_NOTHING;
    const char *u = URL.toStdString().c_str();
    curl_easy_setopt(m_curl, CURLOPT_URL, u);
    curl_easy_setopt(m_curl, CURLOPT_NOPROGRESS, 0);
    curl_easy_setopt(m_curl, CURLOPT_PROGRESSFUNCTION, ProgressCallback);
    curl_easy_setopt(m_curl, CURLOPT_PROGRESSDATA, this);

    m_runflag = RUN;
    res = curl_easy_perform(m_curl);
    if(res == CURLE_OK){
        m_curldownelement->OK();
    }

    fclose(m_File);
    m_File = nullptr;
    return true;
}

size_t CurlDown::wirtefunc(void *ptr, size_t size, size_t nmemb, void *stream)
{
    CurlDown *p = reinterpret_cast<CurlDown*>(stream);
    if(p->m_runflag == RUN){
        return fwrite(ptr, size, nmemb, p->m_File);
    }

    return 0;
}

int CurlDown::ProgressCallback(void *stream, double dltotal, double dlnow, double ultotal, double ulnow)
{
    CurlDown* p = reinterpret_cast<CurlDown*>(stream);

    if ( p->m_runflag == RUN )
    {
        if(dlnow < p->m_pos)
            dlnow = dlnow + p->m_pos;
        p->m_curldownelement->Progress(dltotal, dlnow);

       // curl_off_t speed;
       // curl_easy_getinfo(p->m_curl,CURLINFO_SPEED_DOWNLOAD, &speed);
       // p->m_curldownelement->SetSpeed(speed);

    }
    return 0;

}




















