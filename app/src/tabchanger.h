#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include <QEvent>

class TabChanger : public QTabWidget {
    Q_OBJECT
 protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
 public:
    explicit TabChanger(QWidget *parent = Q_NULLPTR);
};
