#include "Connecter.h"
#include "texteditor.h"

Connecter& Connecter::instance() {
    static Connecter connecter;
    return connecter;
}

void Connecter::ConnectToolBarToEditor(TextEditor *editor) {
    auto actions = m_toolbar->actions();

    QObject::connect(actions[1], &QAction::triggered, editor, &TextEditor::copy);
    QObject::connect(actions[2], &QAction::triggered, editor, &TextEditor::cut);
    QObject::connect(actions[3], &QAction::triggered, editor, &TextEditor::paste);
    QObject::connect(actions[5], &QAction::triggered, editor, &TextEditor::find);
    QObject::connect(actions[6], &QAction::triggered, editor, &TextEditor::replace);
    QObject::connect(actions[8], &QAction::triggered, editor, &TextEditor::undo);
    QObject::connect(actions[9], &QAction::triggered, editor, &TextEditor::redo);
    QObject::connect(actions[10], &QAction::triggered, editor, &TextEditor::Save);
}

void Connecter::setToolbar(QToolBar *tb) {
    m_toolbar = tb;
}

void Connecter::setLogger(Logger *logger) {
    m_logger = logger;
}

Logger *Connecter::getLogger() {
    return m_logger;
}

void Connecter::setSettings(Settings *settings) {
    m_setttings = settings;
}

Settings *Connecter::getSettings() {
    return m_setttings;
}
