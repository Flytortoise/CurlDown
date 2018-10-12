#ifndef MIDWIDGET_H
#define MIDWIDGET_H

#include <QWidget>

#include <QPushButton>
#include <QTextEdit>

#include "newtaskwidget.h"
#include "listwidget.h"

class MidWidget : public QWidget
{
    Q_OBJECT
public:
    explicit MidWidget(QWidget *parent = nullptr);


public slots:
    void RevUrlDown(QString DownPath, QString FileName, QString SavePath);

private:
    void CreateInit();
    void CreateLayout();

    enum{
        CLEARBUTTON,
        NEWTASKBUTTON,
        MENUBUTTON,
        ENDBUTTON
    };

private:
    ListWidget *m_ListWidget;
    QPushButton *m_button[ENDBUTTON];

    NewTaskWidget *m_NewTaskWidget;

};

#endif // MIDWIDGET_H
