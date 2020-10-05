#include "emptywidget.h"
#include "texteditor.h"
#include "tabchanger.h"

EmptyWidget::EmptyWidget(QWidget *parent) : QWidget(parent){
    setLayout(new QGridLayout);
    setAcceptDrops(true);
}

void EmptyWidget::dropEvent(QDropEvent *event) {
    qDebug() << event->pos().x() << " " << event->pos().y() << ": " << size().width() << ":" << size().height();
}
void EmptyWidget::dragEnterEvent(QDragEnterEvent *event) {
    event->acceptProposedAction();
}
void EmptyWidget::dragMoveEvent(QDragMoveEvent *event) {
    event->accept();
}
void EmptyWidget::dragLeaveEvent(QDragLeaveEvent *event) {
    event->accept();
}
