#include <QFileSystemModel>
#include "projectview.h"
#include "emptywidget.h"

ProjectView::ProjectView(QWidget *parent) : QTreeView(parent) {
    setAcceptDrops(true);
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
