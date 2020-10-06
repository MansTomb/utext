#include "Connecter.h"
#include "texteditor.h"

Connecter& Connecter::instance() {
    static Connecter connecter;
    return connecter;
}

void Connecter::ConnectToolBarToEditor(TextEditor *editor) {
    auto actions = toolbar->actions();

    QObject::connect(actions[1], &QAction::triggered, editor, &TextEditor::copy);
    QObject::connect(actions[2], &QAction::triggered, editor, &TextEditor::cut);
    QObject::connect(actions[3], &QAction::triggered, editor, &TextEditor::paste);
    QObject::connect(actions[5], &QAction::triggered, editor, &TextEditor::addText);
    QObject::connect(actions[6], &QAction::triggered, editor, &TextEditor::addText);
    QObject::connect(actions[8], &QAction::triggered, editor, &TextEditor::undo);
    QObject::connect(actions[9], &QAction::triggered, editor, &TextEditor::redo);
}

void Connecter::setToolbar(QToolBar *tb) {
    toolbar = tb;
}
