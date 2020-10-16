#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QTreeView>
#include <QEvent>
#include <QDrag>
#include <QDragEnterEvent>
#include <QDebug>
#include <QMimeData>
#include <QApplication>

class ProjectView : public QTreeView {
 Q_OBJECT
 protected:
    void dragMoveEvent(QDragMoveEvent *event) override;
    void mouseDoubleClickEvent(QMouseEvent *event) override;
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragLeaveEvent(QDragLeaveEvent *event) override;
    void dropEvent(QDropEvent *event) override;
 public:
    explicit ProjectView(QWidget *parent = Q_NULLPTR);
 public slots:
    void ShowContextMenu(const QPoint &pos);
 private:
    void CreateFile(QString path);
    void CreateFolder(QString path);
    void Rename(QString file);
    void Delete(QString file);
};
