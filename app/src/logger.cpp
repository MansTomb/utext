#include "logger.h"
#include "Connecter.h"

Logger::Logger(QWidget *parent) : QTextEdit(parent) {
    Connecter::instance().setLogger(this);
}

void Logger::WriteToLog(QString message) {
    insertPlainText(QDate::currentDate().toString("[dd:MM:yyyy] "));
    insertPlainText(message.append("\n"));
}
