#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "midwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    MidWidget *m_midwidget;

};

#endif // MAINWINDOW_H
