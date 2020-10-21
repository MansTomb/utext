#pragma once

#include <QWidget>
#include <QLineEdit>

#include "tabchanger.h"
#include "texteditor.h"
#include "search.h"
#include "replace.h"

class EditorLayout : public QWidget {
 Q_OBJECT
 public:
    explicit EditorLayout(QFile *file = Q_NULLPTR, QWidget *parent = Q_NULLPTR);

    QFile *file();
    TextEditor *editor();
 public slots:
    void setSearchHidden(QString selectedText);
    void setReplaceHidden(QString selectedText);
 signals:
    void PipeForReplace(QString from, QString to, bool isRegex);
 private:
    QFile *m_file = Q_NULLPTR;
    TextEditor *m_editor = Q_NULLPTR;
    SearchBar *m_search = Q_NULLPTR;
    ReplaceBar *m_replace = Q_NULLPTR;
};
