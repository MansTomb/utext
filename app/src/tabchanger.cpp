#include "tabchanger.h"
#include "texteditor.h"

#include <QDebug>

TabChanger::TabChanger(QWidget *parent) : QTabWidget(parent) {
    insertTab(0, new TextEditor, "Log");
    setAcceptDrops(true);
}
void TabChanger::dragEnterEvent(QDragEnterEvent *event) {
    event->acceptProposedAction();
}
void TabChanger::dragMoveEvent(QDragMoveEvent *event) {
    event->accept();
}
void TabChanger::dragLeaveEvent(QDragLeaveEvent *event) {
    event->accept();
}
void TabChanger::dropEvent(QDropEvent *event) {
    qDebug() << event->pos().x() << " " << event->pos().y() << " TabChanger";
}
