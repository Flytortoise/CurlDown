#include "newtaskwidget.h"

#include <QGridLayout>
#include <QStringList>
#include <QToolTip>
#include <QCoreApplication>

NewTaskWidget::NewTaskWidget(QDialog *parent) : QDialog(parent)
{
    this->setWindowTitle(tr("新建任务"));
    CreateInit();
    CreateLayout();

    this->setFixedSize(373,152);
    this->setWindowFlags(Qt::Tool);
}

void NewTaskWidget::CreateInit()
{
    m_Label[DOWNPATH] = new QLabel(tr("下载地址:"));
    m_Label[FILENAME] = new QLabel(tr("文件名称:"));
    m_Label[SAVEPATH] = new QLabel(tr("保存路径:"));
    m_Label[FILESIZE] = new QLabel(tr("文件大小:"));
    m_Label[FILESIZEDATA] = new QLabel(tr("大小未知"));

    m_DownPathLineEdit = new QLineEdit();
    connect(m_DownPathLineEdit, SIGNAL(textChanged(const QString&)), this, SLOT(SetSaveName(const QString &)));
    m_FileNameLineEdit = new QLineEdit();


    m_SavePathLineEdit = new QLineEdit();
    m_SavePathLineEdit->setText(QCoreApplication::applicationDirPath());

    m_OpenSavePathButton = new QPushButton(tr("打开文件"));
    connect(m_OpenSavePathButton, &QPushButton::clicked, this,[&](){
        m_SavePathLineEdit->setText(QFileDialog::getExistingDirectory(nullptr,tr("浏览文件夹"),"."));
    });

    m_OpenBTButton = new QPushButton(tr("打开BT种子"));
    m_DownButton = new QPushButton(tr("立即下载"));
    connect(m_DownButton, SIGNAL(clicked()), this, SLOT(StartDown()));

    m_CancelButton = new QPushButton(tr("取消"));
    connect(m_CancelButton, SIGNAL(clicked()),this, SLOT(close()));

}

void NewTaskWidget::CreateLayout()
{
    QGridLayout *mainLayout = new QGridLayout(this);

    mainLayout->addWidget(m_Label[DOWNPATH],0,0);
    mainLayout->addWidget(m_DownPathLineEdit, 0, 1, 1, 4);

    mainLayout->addWidget(m_Label[FILENAME], 1, 0);
    mainLayout->addWidget(m_FileNameLineEdit, 1, 1, 1, 4);

    mainLayout->addWidget(m_Label[SAVEPATH], 2, 0);
    mainLayout->addWidget(m_SavePathLineEdit, 2, 1, 1, 3);
    mainLayout->addWidget(m_OpenSavePathButton, 2, 4);

    mainLayout->addWidget(m_Label[FILESIZE], 3, 0);
    mainLayout->addWidget(m_Label[FILESIZEDATA], 3, 1);

    mainLayout->addWidget(m_OpenBTButton, 4, 0);
    mainLayout->addWidget(m_DownButton, 4, 3);
    mainLayout->addWidget(m_CancelButton, 4, 4);

}

void NewTaskWidget::SetSaveName(const QString &filePath)
{
    if(filePath.size() == 0)
        return;

    QStringList fileList = filePath.split("/");
    m_FileNameLineEdit->setText(fileList.back());
}

void NewTaskWidget::StartDown()
{
    QString DownPath = m_DownPathLineEdit->text();
    if(DownPath.size() == 0){
        QToolTip::showText(m_DownPathLineEdit->mapToGlobal(QPoint(20,0)),tr("下载地址不能为空"));
        return;
    }

    QString FileName = m_FileNameLineEdit->text();

    QString SavePath = m_SavePathLineEdit->text();
    if(SavePath.size() == 0){
        QToolTip::showText(m_SavePathLineEdit->mapToGlobal(QPoint(20,0)),tr("保存路径不能为空"));
        return;
    }

    emit CurlDown(DownPath, FileName, SavePath);
    this->close();
}


















