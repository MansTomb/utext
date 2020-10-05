#include "texteditor.h"
#include "Connecter.h"

TextEditor::TextEditor(QWidget *parent) : QPlainTextEdit(parent) {
    installEventFilter(new Filter);
    Connecter::instance().ConnectToolBarToEditor(this);
}

void TextEditor::addText() {
    if (hasFocus())
        appendPlainText("124");
}

bool Filter::eventFilter(QObject *object, QEvent *event) {
    if (event->type() == QEvent::ShortcutOverride) {
        return true;
    }
    return false;
}
