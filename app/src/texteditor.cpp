#include <QtGui/QPainter>
#include <QtGui/QTextBlock>
#include "texteditor.h"
#include "Connecter.h"

TextEditor::TextEditor(QFile *file, QWidget *parent) : m_file(file), QTextEdit(parent) {
    m_highlighter = new Highlighter(document());
    installEventFilter(new Filter);
    Connecter::instance().ConnectToolBarToEditor(this);

    file->open(QIODevice::ReadWrite);
    setPlainText(file->readAll());
    file->close();
}

void TextEditor::addText() {
    if (hasFocus())
        insertPlainText("124");
}
void TextEditor::focusInEvent(QFocusEvent *e) {
    QTextEdit::focusInEvent(e);
    emit InFocus(this);
}

bool Filter::eventFilter(QObject *object, QEvent *event) {
    return event->type() == QEvent::ShortcutOverride;
}


void TextEditor::copy() {
    if (hasFocus())
        QTextEdit::copy();
}
void TextEditor::paste() {
    if (hasFocus())
        QTextEdit::paste();
}
void TextEditor::cut() {
    if (hasFocus())
        QTextEdit::cut();
}
void TextEditor::find() {

}
void TextEditor::replace() {

}
void TextEditor::undo() {
    if (hasFocus())
        QTextEdit::undo();
}
void TextEditor::redo() {
    if (hasFocus())
        QTextEdit::redo();
}
QFile *TextEditor::file() {
    return m_file;
}
