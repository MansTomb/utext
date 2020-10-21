#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include <QEvent>
#include <QMetaMethod>
#include <QFile>
#include <QMimeData>
#include <QSettings>

class TabChanger : public QTabWidget {
 Q_OBJECT
 protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
 public:
    virtual ~TabChanger();
 protected:
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
 public:
    explicit TabChanger(int x = 0, int y = 0, QWidget *parent = Q_NULLPTR);
    void AddPage(QString label, QFile *file);
    void AddPage(QWidget *editor);
    int x();
    int y();
 public slots:
    void ShowContextMenu(const QPoint &pos);
 private slots:
    void CloseTab(int index);
 signals:
    void SplitHorizontaly(const int x, const int y, QWidget *editor);
    void SplitVerticaly(const int x, const int y, QWidget *editor);
    void TabFocused(QWidget *widget);
 private:
    int m_x, m_y;
};
