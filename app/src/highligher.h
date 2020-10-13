#pragma once

#include <QtGui/QSyntaxHighlighter>
#include <QtCore/QRegularExpression>

class Highlighter : public QSyntaxHighlighter
{
    Q_OBJECT

 public:
    explicit Highlighter(QTextDocument *parent = 0);

 protected:
    void highlightBlock(const QString &text) override;

 private:
    struct HighlightingRule
    {
        QRegularExpression pattern;
        QTextCharFormat format;
    };
    QVector<HighlightingRule> highlightingRules;

    QRegularExpression commentStartExpression;
    QRegularExpression commentEndExpression;

    QTextCharFormat keywordFormat;
    QTextCharFormat classFormat;
    QTextCharFormat singleLineCommentFormat;
    QTextCharFormat multiLineCommentFormat;
    QTextCharFormat quotationFormat;
    QTextCharFormat functionFormat;
};
