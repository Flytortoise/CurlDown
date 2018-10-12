#ifndef LISTWIDGET_H
#define LISTWIDGET_H

#include <QWidget>
#include <QVector>
#include <QVBoxLayout>
#include <QScrollArea>
#include "unitwidget.h"

class ListWidget : public QWidget
{
    Q_OBJECT
public:
    explicit ListWidget(QWidget *parent = nullptr);

    void AddUnitWidget(QString, QString, QString);
    void WidgetUpdate();
    void ClearUnit();

signals:

public slots:
    void CloseUnit(UnitWidget *);

private:
    QVector<UnitWidget *> m_v;
    QVBoxLayout *mainLayout;
    QScrollArea *m_scrollarea;
};

#endif // LISTWIDGET_H
