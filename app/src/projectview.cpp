#include <QFileSystemModel>
#include <QtWidgets/QMenu>
#include "projectview.h"
#include "emptywidget.h"
#include "treeviewcontextdialog.h"
#include "texteditor.h"

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
    auto *file = new QFileInfo(dynamic_cast<QFileSystemModel *>(model())->filePath(currentIndex()));

    if (file->isFile() && parentWidget()->findChild<EmptyWidget *>())
        parentWidget()->findChild<EmptyWidget *>()->AddPageToLastFocus(file->fileName(), new QFile(file->absoluteFilePath()));
}
void ProjectView::ShowContextMenu(const QPoint &pos) {
    QMenu contextMenu(tr("Context menu"), this);
    QAction action1(tr("New File"), this);
    QAction action2(tr("New Folder"), this);
    QAction action3(tr("Rename"), this);
    QAction action4(tr("Delete"), this);
    auto file = dynamic_cast<QFileSystemModel *>(model())->filePath(indexAt(pos));

    contextMenu.addAction(&action1);
    connect(&action1, &QAction::triggered, this, [=] { CreateFile(file);});
    contextMenu.addAction(&action2);
    connect(&action2, &QAction::triggered, this, [=] {CreateFolder(file);});
    contextMenu.addAction(&action3);
    connect(&action3, &QAction::triggered, this, [=] { Rename(file);});
    contextMenu.addAction(&action4);
    connect(&action4, &QAction::triggered, this, [=] { Delete(file);});

    contextMenu.exec(mapToGlobal(pos));
}

void ProjectView::CreateFile(QString path) {
    auto *dialog = new TreeViewContextDialog(this);

    if (dialog->exec()) {
        if (!QFileInfo(path).isDir())
            path.remove(path.lastIndexOf("/"), path.size());
        else
            path.append("/");
        QString text = dialog->getEdit()->text();
        QFile file(path + text);

        file.open(QIODevice::ReadWrite);
        file.close();
    }
}
void ProjectView::CreateFolder(QString path) {
    TreeViewContextDialog *dialog = new TreeViewContextDialog(this);

    if (dialog->exec()) {
        if (QFileInfo(path).isDir())
            path.append("/");
        else
            path.remove(path.lastIndexOf("/"), path.size());
        QString text = dialog->getEdit()->text();
        QDir dir;

        dir.mkpath(path + text);
    }
}
void ProjectView::Rename(QString file) {
    TreeViewContextDialog *dialog = new TreeViewContextDialog(this);

    if (dialog->exec()) {
        QFileInfo info(file);
        QString text = dialog->getEdit()->text();
        QString newName = file;

        newName.remove(newName.lastIndexOf("/"), newName.size()).append("/" + text);
        if (info.isDir()) {
            QDir dir(file);
            dir.rename(file, newName);
        }
        else {
            QFile f(file);
            f.rename(file, newName);
        }
    }
}
void ProjectView::Delete(QString file) {
    QFileInfo info(file);

    if (info.isDir()) {
        QDir dir(file);
        auto filelist =  dir.entryInfoList();

        filelist.removeFirst();
        filelist.removeFirst();

        for (const auto &editor : parent()->findChildren<TextEditor *>())
            for (const auto &ffile : filelist)
                if (ffile.filePath() == editor->file()->fileName())
                    delete editor->parent();
        dir.removeRecursively();
    }
    else {
        QFile f(file);
        f.remove();
    }
}
