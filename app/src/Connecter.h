#pragma once

#include "mainwindow.h"

class Connecter {
 public:
    Connecter(Connecter& other) = delete;
    void operator=(const Connecter& other) = delete;

    static Connecter& instance();
    void setToolbar(QToolBar *tb);
    void ConnectToolBarToEditor(TextEditor *editor);
 protected:
    Connecter() {};

 private:
    QToolBar *toolbar = Q_NULLPTR;
};
