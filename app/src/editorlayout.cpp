#include "editorlayout.h"

EditorLayout::EditorLayout(QFile *file, QWidget *parent) : m_file(file), QWidget(parent) {
    m_editor = new TextEditor(m_file);
    m_search = new QLineEdit;
    m_replace = new QLineEdit;

    m_search->setHidden(true);
    m_replace->setHidden(true);
    m_search->setPlaceholderText("Search");
    m_replace->setPlaceholderText("Replace");
    setLayout(new QVBoxLayout(this));
    layout()->setMargin(0);
    layout()->setSpacing(0);
    layout()->addWidget(m_search);
    layout()->addWidget(m_replace);
    layout()->addWidget(m_editor);

    connect(m_search, &QLineEdit::returnPressed, this, [=]{emit MyReturnSearchPressed(m_search->text(), m_replace->text());});
    connect(m_replace, &QLineEdit::returnPressed, this, [=]{emit MyReturnReplacePressed(m_search->text(), m_replace->text());});
    connect(this, &EditorLayout::MyReturnSearchPressed, m_editor, &TextEditor::SearchInText);
    connect(this, &EditorLayout::MyReturnReplacePressed, m_editor, &TextEditor::ReplaceInText);
    connect(m_editor, &TextEditor::TriggerSearch, this, &EditorLayout::setSearchHidden);
    connect(m_editor, &TextEditor::TriggerReplace, this, &EditorLayout::setReplaceHidden);
}

QFile *EditorLayout::file() {
    return m_file;
}

TextEditor *EditorLayout::editor() {
    return m_editor;
}

void EditorLayout::setSearchHidden(QString selectedText) {
    if (m_search->isHidden()) {
        m_search->setHidden(false);
        m_search->setText(selectedText);
    }
    else {
        m_search->setHidden(true);
        m_replace->setHidden(true);
    }
}

void EditorLayout::setReplaceHidden(QString selectedText) {
    if (m_replace->isHidden()) {
        m_search->setHidden(false);
        m_replace->setHidden(false);
        m_search->setText(selectedText);
    }
    else {
        m_search->setHidden(true);
        m_replace->setHidden(true);
    }
}
