#pragma once

#include <QWidget>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>

class ReplaceBar : public QWidget {
 Q_OBJECT
 public:
    explicit ReplaceBar(QWidget *parent = Q_NULLPTR);
    void Hidden(bool hide);
    QString getText();
 signals:
    void MyReturnPressed(QString to);
 private:
    QLineEdit *replace;
};
