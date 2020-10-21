#include "search.h"

SearchBar::SearchBar(QWidget *parent) : QWidget(parent) {
    m_search = new QLineEdit(this);
    m_regex = new QPushButton(this);

    m_search->setPlaceholderText(tr("Search (use enter to iterate through finds)"));
    m_regex->setText(tr("Regex: ") + (m_isRegex ? tr("ON") : tr("OFF")));
    setLayout(new QHBoxLayout);
    layout()->setSpacing(0);
    layout()->setMargin(0);
    layout()->addWidget(m_search);
    layout()->addWidget(m_regex);

    connect(m_search, &QLineEdit::returnPressed, this, [=] { emit MyReturnPressed(m_search->text(), m_isRegex); });
    connect(m_regex, &QPushButton::clicked, this, &SearchBar::ButtonPressed);
}

void SearchBar::ButtonPressed(bool checked) {
    m_isRegex = !m_isRegex;
    m_regex->setText(tr("Regex: ") + (m_isRegex ? tr("ON") : tr("OFF")));
}
void SearchBar::Hidden(bool hide) {
    this->setHidden(hide);
    m_search->setHidden(hide);
    m_regex->setHidden(hide);
}
void SearchBar::setText(QString text) {
    m_search->setText(text);
}
QString SearchBar::getText() {
    return m_search->text();
}
bool SearchBar::isRegex() {
    return m_isRegex;
}
