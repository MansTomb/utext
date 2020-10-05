#include "texteditor.h"

TextEditor::TextEditor(QWidget *parent) : QPlainTextEdit(parent) {
    installEventFilter(new Filter);
}

bool Filter::eventFilter(QObject *object, QEvent *event) {
    if (event->type() == QEvent::ShortcutOverride) {
        return true;
    }
    return false;
}
