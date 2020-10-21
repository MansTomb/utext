#include "editorlayout.h"

EditorLayout::EditorLayout(QFile *file, QWidget *parent) : QWidget(parent), m_file(file) {
    m_editor = new TextEditor(m_file, this);
    m_search = new SearchBar(this);
    m_replace = new ReplaceBar(this);

    m_search->Hidden(true);
    m_replace->Hidden(true);
    setLayout(new QVBoxLayout(this));
    layout()->setMargin(0);
    layout()->setSpacing(0);
    layout()->addWidget(m_search);
    layout()->addWidget(m_replace);
    layout()->addWidget(m_editor);

    connect(m_search, &SearchBar::MyReturnPressed, m_editor, &TextEditor::SearchInText);
    connect(m_replace,
            &ReplaceBar::MyReturnPressed,
            this,
            [=] { emit PipeForReplace(m_search->getText(), m_replace->getText(), m_search->isRegex()); });
    connect(this, &EditorLayout::PipeForReplace, m_editor, &TextEditor::ReplaceInText);
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
        m_search->Hidden(false);
        m_search->setText(selectedText);
    } else {
        m_search->Hidden(true);
        m_replace->Hidden(true);
    }
}

void EditorLayout::setReplaceHidden(QString selectedText) {
    if (m_replace->isHidden()) {
        m_search->Hidden(false);
        m_replace->Hidden(false);
        m_search->setText(selectedText);
    } else {
        m_search->Hidden(true);
        m_replace->Hidden(true);
    }
}
