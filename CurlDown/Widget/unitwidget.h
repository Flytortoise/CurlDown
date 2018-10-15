#ifndef UNITWIDGET_H
#define UNITWIDGET_H

#include <QWidget>

#include <QLabel>

#include <QPushButton>
#include <QDebug>
#include <QTimer>

struct DownInformation{
    QString DownPath;
    QString FileName;
    QString SavePath;
};


class UnitWidget:public QWidget
{
    Q_OBJECT
public:
    explicit UnitWidget(QWidget *parent = nullptr);

    void SetInformation(QString DownPath, QString FileName, QString SavePath){
        m_information.DownPath = DownPath;
        m_information.FileName = FileName;
        m_FileNameLabel->setText(FileName);
        m_information.SavePath = SavePath;
        //qDebug() << m_information.FileName;
    }

    DownInformation GetInformation(){
        return m_information;
    }

signals:
    void Close(UnitWidget *);
    void Pause();

public slots:
    void CancelFunc();
    void OK();
    void OnProgress(double dltotal, double dlnow);

    void TimeUpdate();

private:
    void CreateInit();
    void CreateLayout();

private:
    QLabel *m_FileNameLabel;
    QLabel *m_ProgressBarLabel;
    QLabel *m_SpeedLabel;
    QPushButton *m_PauseButton;
    QPushButton *m_OpenFolderButton;
    QPushButton *m_CancelButton;

    QTimer *m_timer;

    DownInformation m_information;
    double m_nowSize;
    double m_frontSize;
};

#endif // UNITWIDGET_H
