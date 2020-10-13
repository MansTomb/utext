#include <QFileSystemModel>
#include <QtWidgets/QMenu>
#include "projectview.h"
#include "emptywidget.h"

ProjectView::ProjectView(QWidget *parent) : QTreeView(parent) {
    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    setAcceptDrops(true);
    connect(this, &ProjectView::customContextMenuRequested, this, &ProjectView::ShowContextMenu);
}
void ProjectView::dragEnterEvent(QDragEnterEvent *event) {
    event->acceptProposedAction();
}
void ProjectView::dragLeaveEvent(QDragLeaveEvent *event) {
    event->accept();
}
void ProjectView::dragMoveEvent(QDragMoveEvent *event) {
    event->accept();
}

void ProjectView::dropEvent(QDropEvent *event) {
    if (!event->mimeData()->hasUrls())
        return;
    auto droppedData = event->mimeData()->urls();
    if (droppedData.count() == 1) {
        if (!QDir(droppedData.at(0).toString().remove(0, 7)).exists())
            return;
        auto index = dynamic_cast<QFileSystemModel *>(model())->index(droppedData.at(0).toString().remove(0, 7));
        setRootIndex(index);
    }
}

void ProjectView::mouseDoubleClickEvent(QMouseEvent *event) {
    QTreeView::mouseDoubleClickEvent(event);
    QFileInfo *file = new QFileInfo(dynamic_cast<QFileSystemModel *>(model())->filePath(currentIndex()));

    if (file->isFile() && parentWidget()->findChild<EmptyWidget *>())
        parentWidget()->findChild<EmptyWidget *>()->AddPageToLastFocus(file->fileName(), new QFile(file->absoluteFilePath()));
}

void ProjectView::ShowContextMenu(const QPoint &pos) {
    QMenu contextMenu(tr("Context menu"), this);
    QAction action1(tr("New File"), this);
    QAction action2(tr("New Folder"), this);
    QAction action3(tr("Delete"), this);
    auto file = dynamic_cast<QFileSystemModel *>(model())->filePath(indexAt(pos));

    contextMenu.addAction(&action1);
    connect(&action1, &QAction::triggered, this, [=] { qDebug() << "Create File In: " << file;});
    contextMenu.addAction(&action2);
    connect(&action2, &QAction::triggered, this, [=] { qDebug() << "Create Folder In: " << file;});
    contextMenu.addAction(&action3);
    connect(&action3, &QAction::triggered, this, [=] { qDebug() << "Delete: " << file;});

    contextMenu.exec(mapToGlobal(pos));
}
