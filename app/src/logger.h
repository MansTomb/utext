#pragma once

#include <QPlainTextEdit>
#include <QGridLayout>
#include <QDebug>
#include <QApplication>
#include <QToolBar>
#include <QWindow>
#include <QFontMetrics>
#include <QDate>

#include "highligher.h"

class Logger : public QTextEdit {
    Q_OBJECT
 public:
    explicit Logger(QWidget *parent = Q_NULLPTR);
    void WriteToLog(QString message);
};
