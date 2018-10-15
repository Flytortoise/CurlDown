#include "curldownelement.h"

#include "curl/curl.h"

#include <QDebug>

CurlDownElement::CurlDownElement(QObject *parent):QThread(parent)
{
    m_curldown = new CurlDown(this);
}

CurlDownElement::~CurlDownElement()     //delete CurlDownElement有问题
{
    Stop();
    quit();        //告诉事件循环返回并退出
    wait();        //等待线程结束
}


void CurlDownElement::Stop()
{
    if(m_curldown){
        m_curldown->Stop();
        delete m_curldown;
        m_curldown = nullptr;
    }
}

void CurlDownElement::run()
{

    QString FileName = m_info.SavePath + '\\' + m_info.FileName;

    m_curldown->SetTimeOut(1);
    m_curldown->DownFile(FileName, m_info.DownPath);
}

void CurlDownElement::OK()
{
    emit HasFinished();
}

void CurlDownElement::Pause()
{
    if(m_curldown){         //暂停后 取消依然有bug
        m_curldown->Pause();
    }
}

void CurlDownElement::Progress(double dltotal, double dlnow)
{
    emit OnProgress(dltotal, dlnow);
}
