#pragma once

#include <QPlainTextEdit>
#include <QGridLayout>
#include <QDebug>
#include <QApplication>
#include <QToolBar>
#include <QWindow>
#include <QFontMetrics>

#include "highligher.h"

class Filter : public QObject {
 Q_OBJECT
 public:
    bool eventFilter(QObject *object, QEvent *event);
};

class TextEditor : public QTextEdit {
    Q_OBJECT

 protected:
    void focusInEvent(QFocusEvent *e) override;
 public:
    explicit TextEditor(QFile *file, QWidget *parent = Q_NULLPTR);
    QFile *file();
 public slots:
    void addText();
    void copy();
    void paste();
    void cut();
    void find();
    void replace();
    void undo();
    void redo();
 signals:
    void InFocus(QWidget *widget);
 private:
    Highlighter *m_highlighter;
    QFile *m_file;
};
