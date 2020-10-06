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
    Q_OBJECT
 public:
    explicit EmptyWidget(QWidget *parent = Q_NULLPTR);
 public slots:
    void addNewWindow(TabChanger *tabs);
 protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
 private:
    void Split(const int x, const int y);

    QSplitter *split;
};
