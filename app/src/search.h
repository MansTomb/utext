#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

class SearchBar : public QWidget {
 Q_OBJECT
 public:
    explicit SearchBar(QWidget *parent = Q_NULLPTR);
    void Hidden(bool hide);
    void setText(QString text);
    QString getText();
    bool isRegex();
 signals:
    void MyReturnPressed(QString from, bool isRegex);
 private:
    void ButtonPressed(bool checked);

    QLineEdit *m_search;
    QPushButton *m_regex;
    bool m_isRegex = {false};
};
