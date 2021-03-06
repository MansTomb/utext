#include "htmlhighlighter.h"

HtmlHighLighter::HtmlHighLighter(QTextDocument *document)
    : QSyntaxHighlighter(document) {
    QTextCharFormat entityFormat;
    entityFormat.setForeground(QColor(0, 128, 0));
    setFormatFor(Entity, entityFormat);

    QTextCharFormat tagFormat;
    tagFormat.setForeground(QColor("#A93CD4"));
    setFormatFor(Tag, tagFormat);

    QTextCharFormat commentFormat;
    commentFormat.setForeground(QColor(128, 10, 74));
    setFormatFor(Comment, commentFormat);
}

void HtmlHighLighter::setFormatFor(Construct construct, const QTextCharFormat &format) {
    m_formats[construct] = format;
    rehighlight();
}

void HtmlHighLighter::highlightBlock(const QString &text) {
    int state = previousBlockState();
    int len = text.length();
    int start = 0;
    int pos = 0;

    while (pos < len) {
        switch (state) {
            case NormalState:
            default:
                while (pos < len) {
                    QChar ch = text.at(pos);
                    if (ch == '<') {
                        if (text.mid(pos, 4) == "<!--") {
                            state = InComment;
                        } else {
                            state = InTag;
                        }
                        break;
                    } else if (ch == '&') {
                        start = pos;
                        while (pos < len
                            && text.at(pos++) != ';');
                        setFormat(start, pos - start,
                                  m_formats[Entity]);
                    } else {
                        ++pos;
                    }
                }
                break;
            case InComment:start = pos;
                while (pos < len) {
                    if (text.mid(pos, 3) == "-->") {
                        pos += 3;
                        state = NormalState;
                        break;
                    } else {
                        ++pos;
                    }
                }
                setFormat(start, pos - start,
                          m_formats[Comment]);
                break;
            case InTag:QChar quote = QChar::Null;
                start = pos;
                while (pos < len) {
                    QChar ch = text.at(pos);
                    if (quote.isNull()) {
                        if (ch == "\"" || ch == '"') {
                            quote = ch;
                        } else if (ch == '>') {
                            ++pos;
                            state = NormalState;
                            break;
                        }
                    } else if (ch == quote) {
                        quote = QChar::Null;
                    }
                    ++pos;
                }
                setFormat(start, pos - start, m_formats[Tag]);
        }
    }
    setCurrentBlockState(state);
}
