#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include <QEvent>
#include <QMetaMethod>

class TabChanger : public QTabWidget {
    Q_OBJECT
 protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
 public:
    explicit TabChanger(int x = 0, int y = 0, QWidget *parent = Q_NULLPTR);
    int x();
    int y();
 public slots:
    void ShowContextMenu(const QPoint& pos);
 signals:
    void SplitHorizontaly(const int x, const int y);
    void SplitVerticaly(const int x, const int y);
 private:
    int m_x, m_y;
};
