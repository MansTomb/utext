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
    void SearchInText(QString from, QString to);
    void ReplaceInText(QString from, QString to);
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
    void TriggerSearch(QString selectedText);
    void TriggerReplace(QString selectedText);
 private:
    Highlighter *m_highlighter = Q_NULLPTR;
    QFile *m_file = Q_NULLPTR;
};
