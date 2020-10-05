#pragma once

#include <QWidget>
#include <QGridLayout>
#include <QDebug>
#include <QEvent>
#include <QDrag>
#include <QDropEvent>
#include <QFormLayout>
#include <QSplitter>

#include "tabchanger.h"

class EmptyWidget : public QWidget {
 public:
    explicit EmptyWidget(QWidget *parent = Q_NULLPTR);
    void addNewWindow(TabChanger *tabs, int x, int y);
 protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
 private:
    QSplitter *split;
    QVector<QSplitter *> splitters;
};
