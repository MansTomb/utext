#pragma once

#include <QWidget>
#include <QLineEdit>

#include "tabchanger.h"
#include "texteditor.h"

class EditorLayout : public QWidget {
 public:
    explicit EditorLayout(QFile *file = Q_NULLPTR, QWidget *parent = Q_NULLPTR);

    QFile *file();
    TextEditor *editor();
 public slots:
    void setSearchHidden();
    void setReplaceHidden();
 private:
    QFile *m_file = Q_NULLPTR;
    TextEditor *m_editor = Q_NULLPTR;
    QLineEdit *m_search = Q_NULLPTR;
    QLineEdit *m_replace = Q_NULLPTR;
};
