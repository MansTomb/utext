#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QGridLayout>
#include <QEvent>

class TabChanger : public QTabWidget {
    Q_OBJECT

 public:
    explicit TabChanger(QWidget *parent = Q_NULLPTR);
};
