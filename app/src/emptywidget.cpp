#include "emptywidget.h"

EmptyWidget::EmptyWidget(QWidget *parent) : QWidget(parent){
    setLayout(new QGridLayout);
}

void EmptyWidget::addWidgetToLayout(QWidget *widget) {
    layout()->addWidget(widget);
}
