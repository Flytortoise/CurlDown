#include "midwidget.h"

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QDebug>


MidWidget::MidWidget(QWidget *parent) : QWidget(parent)
{

    CreateInit();
    CreateLayout();
}

void MidWidget::CreateInit()
{
    m_ListWidget = new ListWidget();

    m_NewTaskWidget = new NewTaskWidget();
    connect(m_NewTaskWidget, SIGNAL(CurlDown(QString, QString, QString)),
            this, SLOT(RevUrlDown(QString, QString, QString)));

    m_button[CLEARBUTTON] = new QPushButton(tr("清空任务"));
    connect(m_button[CLEARBUTTON], &QPushButton::clicked, this, [&](){
        m_ListWidget->ClearUnit();
    });

    m_button[NEWTASKBUTTON] = new QPushButton(tr("新建任务"));
    connect(m_button[NEWTASKBUTTON], &QPushButton::clicked, this,[&](){
       m_NewTaskWidget->exec();
    });
    m_button[MENUBUTTON] = new QPushButton(tr("菜单"));
}

void MidWidget::CreateLayout()
{
    QHBoxLayout *hLayout = new QHBoxLayout();
    hLayout->addWidget(m_button[CLEARBUTTON]);
    hLayout->addStretch(1);
    hLayout->addWidget(m_button[NEWTASKBUTTON]);
    hLayout->addWidget(m_button[MENUBUTTON]);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addWidget(m_ListWidget);
    mainLayout->addLayout(hLayout);

    this->setLayout(mainLayout);
}

void MidWidget::RevUrlDown(QString DownPath, QString FileName, QString SavePath)
{
    //qDebug() << FileName;
    m_ListWidget->AddUnitWidget(DownPath, FileName, SavePath);
}
