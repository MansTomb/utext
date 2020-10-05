#pragma once

#include <QWidget>
#include <QGridLayout>

class EmptyWidget : public QWidget {
 public:
    explicit EmptyWidget(QWidget *parent = Q_NULLPTR);
    void addWidgetToLayout(QWidget *widget);
};
