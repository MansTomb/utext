#include "Connecter.h"
#include "texteditor.h"

Connecter& Connecter::instance() {
    static Connecter connecter;
    return connecter;
}

void Connecter::ConnectToolBarToEditor(TextEditor *editor) {
    auto actions = toolbar->actions();

    for (const auto &item : actions) {
        QObject::connect(item, &QAction::triggered, editor, &TextEditor::addText);
    }
}

void Connecter::setToolbar(QToolBar *tb) {
    toolbar = tb;
}
