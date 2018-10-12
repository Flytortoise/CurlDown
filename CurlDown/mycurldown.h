#ifndef MY_CURLDOWN_H
#define MY_CURLDOWN_H

#include "curl/curl.h"
#include <QString>
//#include "CurlDownElement.h"

class CurlDownElement;

class CurlDown
{
public:
    enum{
        STOP,
        RUN,
        PAUSE,
    };

    CurlDown(CurlDownElement *curl);
    ~CurlDown();

    bool DownFile(QString FileName, QString URL);
    bool SetFileName(QString FileName);
    bool SetResumeForm(long pos);               //设置断点续传
    bool SetResumeFormLarge(long long pos);     //设置大文件断电续传
    bool SetTimeOut(int timeout);
    void Pause();
    void Stop();


    static size_t wirtefunc(void *ptr, size_t size, size_t nmemb, void *stream);
    static int ProgressCallback(void *stream, double dltotal, double dlnow, double ultotal, double ulnow);
private:
    CURL *m_curl;
    CurlDownElement *m_curldownelement;
    FILE *m_File;

    int m_runflag;
    long long m_pos;

};

#endif // CURLDOWN_H
