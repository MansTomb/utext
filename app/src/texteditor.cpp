#include "texteditor.h"
#include "Connecter.h"

TextEditor::TextEditor(QFile *file, QWidget *parent) : QPlainTextEdit(parent) {
    installEventFilter(new Filter);
    Connecter::instance().ConnectToolBarToEditor(this);

    file->open(QIODevice::ReadWrite);
    setPlainText(file->readAll());
}

void TextEditor::addText() {
    if (hasFocus())
        appendPlainText("124");
}
void TextEditor::focusInEvent(QFocusEvent *e) {
    QPlainTextEdit::focusInEvent(e);
    emit InFocus(this);
}

bool Filter::eventFilter(QObject *object, QEvent *event) {
    if (event->type() == QEvent::ShortcutOverride) {
        return true;
    }
    return false;
}
