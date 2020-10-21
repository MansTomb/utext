#include "replace.h"

ReplaceBar::ReplaceBar(QWidget *parent) : QWidget(parent) {
    replace = new QLineEdit(this);

    replace->setPlaceholderText(tr("Replace (use enter to replace finds one by one)"));
    setLayout(new QHBoxLayout);
    layout()->setSpacing(0);
    layout()->setMargin(0);
    layout()->addWidget(replace);

    connect(replace, &QLineEdit::returnPressed, this, [=] { emit MyReturnPressed(replace->text()); });
}

void ReplaceBar::Hidden(bool hide) {
    this->setHidden(hide);
    replace->setHidden(hide);
}
QString ReplaceBar::getText() {
    return replace->text();
}
