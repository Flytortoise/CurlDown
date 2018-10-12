#include "listwidget.h"
#include <QPalette>
#include "curldownmanager.h"
#include <QVBoxLayout>
#include <QDebug>

ListWidget::ListWidget(QWidget *parent) : QWidget(parent)
{
    QPalette p(this->palette());
    p.setColor(QPalette::Background, Qt::white);
    this->setAutoFillBackground(true);
    this->setPalette(p);

    mainLayout = nullptr;
    //m_scrollarea = new QScrollArea;

}

void ListWidget::AddUnitWidget(QString DownPath, QString FileName, QString SavePath)
{
    //qDebug() << FileName;
    UnitWidget *tmp = new UnitWidget();
    tmp->SetInformation(DownPath, FileName, SavePath);
    CurlDownManager::GetCurDownManager()->AddCurlDown(tmp);

    m_v.append(tmp);
    connect(tmp, SIGNAL(Close(UnitWidget *)), this, SLOT(CloseUnit(UnitWidget *)));
    WidgetUpdate();
}

void ListWidget::WidgetUpdate()
{
    if(mainLayout)
        delete mainLayout;

    mainLayout = new QVBoxLayout;
    for(auto x : m_v){
        mainLayout->addWidget(x);
    }

    mainLayout->addStretch();

    this->setLayout(mainLayout);
    //m_scrollarea->setWidget(this);
}

void ListWidget::CloseUnit(UnitWidget *ptr)
{
    CurlDownManager::GetCurDownManager()->EraseCurlDown(ptr);

    auto it = m_v.begin();
    while(it != m_v.end()){
        if(*it == ptr)
            break;
        ++it;
    }

    m_v.erase(it);
    delete ptr;

    WidgetUpdate();
}

void ListWidget::ClearUnit()
{
    CurlDownManager::GetCurDownManager()->ClearManager();

    for(int i = 0; i < m_v.size(); i++)
        delete m_v[i];

    m_v.clear();
    WidgetUpdate();
}

