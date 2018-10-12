#ifndef CURLDOWNELEMENT_H
#define CURLDOWNELEMENT_H

#include "unitwidget.h"
#include <QThread>
#include <QMutexLocker>
#include "curl/curl.h"
#include "mycurldown.h"
#include <QDebug>

class CurlDownElement : public QThread
{
    Q_OBJECT
public:
    explicit CurlDownElement(QObject *parent = nullptr);
    void SetInformation(DownInformation info){
        //qDebug() << info.FileName;
        m_info = info;
    }

    ~CurlDownElement();

    void Stop();
    void OK();
    void Progress(double dltotal, double dlnow);
    void SetSpeed(double speed);

signals:
    void HasFinished();
    void OnProgress(double, double);
    void OnSpeed(QString);

public slots:
    void Pause();

protected:
    void run();

private:
    DownInformation m_info;


    CurlDown *m_curldown;
};

#endif // CURLDOWNELEMENT_H
