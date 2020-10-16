#include <QtGui/QPainter>
#include <QtGui/QTextBlock>

#include "texteditor.h"
#include "Connecter.h"
#include "htmlhighlighter.h"

TextEditor::TextEditor(QFile *file, QWidget *parent) : m_file(file), QTextEdit(parent) {
    if (m_file->fileName().remove(0, m_file->fileName().lastIndexOf(".")) == ".cpp")
        new CppHighLighter(document());
    else
        new HtmlHighLighter(document());
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
    if (hasFocus())
        emit TriggerSearch(textCursor().selectedText());
}
void TextEditor::replace() {
    if (hasFocus())
        emit TriggerReplace(textCursor().selectedText());
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
void TextEditor::SearchInText(QString from, bool isRegex) {
    QList<QTextEdit::ExtraSelection> extraSelections;
    static QTextCursor cursor(document());

    if (cursor.isNull())
        cursor = QTextCursor(document());

    if(!isReadOnly())
    {
        QColor color = QColor(Qt::gray).lighter(130);
        isRegex ? cursor = document()->find(QRegExp(from), cursor) : cursor = document()->find(from, cursor);
        if (!cursor.isNull()) {
            QTextEdit::ExtraSelection extra;
            extra.format.setBackground(color);
            extra.cursor = cursor;
            extraSelections.append(extra);
        }
    }
    setExtraSelections(extraSelections);
}

void TextEditor::ReplaceInText(QString from, QString to, bool isRegex) {
    textCursor().beginEditBlock();
    static QTextCursor cursor(document());

    if (cursor.isNull())
        cursor = QTextCursor(document());

    if (!isReadOnly()) {
        isRegex ? cursor = document()->find(QRegExp(from), cursor) : cursor = document()->find(from, cursor);
        if (!cursor.isNull()) {
            cursor.insertText(to);
        }
    }
    textCursor().endEditBlock();
}

void TextEditor::Save() {
    auto text = document()->toPlainText();

    file()->open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate);
    file()->write(text.toStdString().c_str());
    file()->close();
}

void TextEditor::SaveAtExit() {
    QMessageBox msg;
    QString text;

    text.append(tr("You wanna save file ")).append(file()->fileName().remove(0, file()->fileName().lastIndexOf("/") + 1).append("?"));

    msg.setText(text);
    msg.setStandardButtons(QMessageBox::Save | QMessageBox::Cancel);
    msg.setDefaultButton(QMessageBox::Save);
    if (msg.exec() == QMessageBox::Save)
        Save();
}
