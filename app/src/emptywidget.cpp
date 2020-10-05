#include "emptywidget.h"
#include "texteditor.h"
#include "tabchanger.h"

EmptyWidget::EmptyWidget(QWidget *parent) : QWidget(parent){
    setLayout(new QGridLayout);
    setLayoutDirection(Qt::LayoutDirection::LeftToRight);
    split = new QSplitter(Qt::Orientation::Vertical);
    layout()->addWidget(split);
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
void EmptyWidget::addNewWindow(TabChanger *tabs, int x, int y) {
    while (x >= split->count()) {
        split->addWidget(new QSplitter(Qt::Orientation::Horizontal));
    }
    if (x == -1) {
        split->insertWidget(0, new QSplitter(Qt::Orientation::Horizontal));
        dynamic_cast<QSplitter *>(split->widget(0))->insertWidget(y, tabs);
    }
    else {
        dynamic_cast<QSplitter *>(split->widget(x))->addWidget(tabs);
    }
}
