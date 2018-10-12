#include "unitwidget.h"

#include <QHBoxLayout>
#include <QDesktopServices>
#include <QUrl>

#include "curldownmanager.h"

UnitWidget::UnitWidget(QWidget *parent) : QWidget (parent)
{
    CreateInit();
    CreateLayout();


}

void UnitWidget::CreateInit()
{
    m_FileNameLabel = new QLabel(tr("FileName"));
    m_SpeedLabel = new QLabel(tr(""));
    m_ProgressBarLabel = new QLabel(tr(""));

    m_PauseButton = new QPushButton(tr("暂停"));
    connect(m_PauseButton, &QPushButton::clicked, this,[&](){
        static int UnitFlag = 0;
        if(UnitFlag == 0){
            m_PauseButton->setText(tr("继续"));
            UnitFlag = 1;
        }
        else{
            m_PauseButton->setText(tr("暂停"));
            UnitFlag = 0;
        }

        emit this->Pause();

    });

    m_OpenFolderButton = new QPushButton(tr("文件夹"));
    connect(m_OpenFolderButton, &QPushButton::clicked, this,[&](){
        QDesktopServices::openUrl(QUrl(m_information.SavePath));
    });

    m_CancelButton = new QPushButton(tr("取消"));
    connect(m_CancelButton, SIGNAL(clicked()), this, SLOT(CancelFunc()));

}

void UnitWidget::CreateLayout()
{
    QHBoxLayout *mainLayout = new QHBoxLayout(this);
    mainLayout->addWidget(m_FileNameLabel);
    mainLayout->addWidget(m_ProgressBarLabel);
    mainLayout->addWidget(m_SpeedLabel);
    mainLayout->addWidget(m_PauseButton);
    mainLayout->addWidget(m_OpenFolderButton);
    mainLayout->addWidget(m_CancelButton);
}

void UnitWidget::CancelFunc()
{
    //this->close();
    emit Close(this);
}

void UnitWidget::OK()
{
    m_PauseButton->setEnabled(false);
}

void UnitWidget::OnProgress(double dltotal, double dlnow)
{
    double tmp = dlnow * 100 / dltotal;
    if(tmp > 100 || tmp < 0)
        tmp = 0;

    char buff[10] = {0};
    sprintf(buff," %.1f %%", tmp);

    QString value(buff);
    m_ProgressBarLabel->setText(value);
}

void UnitWidget::OnSpeed(QString value)
{
    //m_SpeedLabel->setText(value);
}
