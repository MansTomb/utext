#pragma once

#include "mainwindow.h"
#include "settings.h"

class Connecter {
 public:
    Connecter(Connecter &other) = delete;
    void operator=(const Connecter &other) = delete;

    static Connecter &instance();
    void setToolbar(QToolBar *tb);
    void setLogger(Logger *logger);
    void setSettings(Settings *settings);
    Settings *getSettings();
    Logger *getLogger();
    void ConnectToolBarToEditor(TextEditor *editor);
 protected:
    Connecter() {};

 private:
    Settings *m_setttings = Q_NULLPTR;
    QToolBar *m_toolbar = Q_NULLPTR;
    Logger *m_logger = Q_NULLPTR;
};
