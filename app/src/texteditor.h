#pragma once

#include <QPlainTextEdit>
#include <QGridLayout>
#include <QDebug>
#include <QApplication>

#include <mainwindow.h>

class Filter : public QObject {
 Q_OBJECT
 public:
    bool eventFilter(QObject *object, QEvent *event);
};

class TextEditor : public QPlainTextEdit {
 public:
    explicit TextEditor(QWidget *parent = Q_NULLPTR);
};
