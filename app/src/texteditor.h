#pragma once

#include <QPlainTextEdit>
#include <QGridLayout>
#include <QDebug>
#include <QApplication>
#include <QToolBar>
#include <QWindow>

class Filter : public QObject {
 Q_OBJECT
 public:
    bool eventFilter(QObject *object, QEvent *event);
};

class TextEditor : public QPlainTextEdit {
    Q_OBJECT

 public:
    explicit TextEditor(QWidget *parent = Q_NULLPTR);
 public slots:
    void addText();
};
