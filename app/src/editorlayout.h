#pragma once

#include <QWidget>
#include <QLineEdit>

#include "tabchanger.h"
#include "texteditor.h"

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
    void MyReturnSearchPressed(QString from, QString to);
    void MyReturnReplacePressed(QString from, QString to);
 private:
    QFile *m_file = Q_NULLPTR;
    TextEditor *m_editor = Q_NULLPTR;
    QLineEdit *m_search = Q_NULLPTR;
    QLineEdit *m_replace = Q_NULLPTR;
};
