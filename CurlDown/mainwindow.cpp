#include "mainwindow.h"
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent)
{
    this->setWindowTitle(tr("CurlDown"));

    m_midwidget = new MidWidget();
    this->setCentralWidget(m_midwidget);

    this->setFixedSize(527,362);
}

MainWindow::~MainWindow()
{
}



