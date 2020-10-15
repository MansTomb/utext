#pragma once

#include "mainwindow.h"

class Connecter {
 public:
    Connecter(Connecter& other) = delete;
    void operator=(const Connecter& other) = delete;

    static Connecter& instance();
    void setToolbar(QToolBar *tb);
    void setLogger(Logger *logger);
    Logger *getLogger();
    void ConnectToolBarToEditor(TextEditor *editor);
 protected:
    Connecter() {};

 private:
    QToolBar *m_toolbar = Q_NULLPTR;
    Logger *m_logger = Q_NULLPTR;
};
