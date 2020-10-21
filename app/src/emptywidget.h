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
    virtual ~EmptyWidget();
    void AddPageToLastFocus(QString label, QFile *file);
 public slots:
    void addNewWindow(TabChanger *tabs);
    void LastFocusedTabController(QWidget *widget);
 protected:
    void dropEvent(QDropEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
 private:
    void Split(const int x, const int y, QWidget *editor);

    QWidget *m_lastFocus{Q_NULLPTR};
    QSplitter *m_split{Q_NULLPTR};
};
