#pragma once

#include "mainwindow.h"

class Connecter {
 public:
    Connecter(Connecter& other) = delete;
    void operator=(const Connecter& other) = delete;

    static Connecter& instance();
    void setToolbar(QToolBar *tb);
//    void setMenuBar(QMenuBar *mb);
    void ConnectToolBarToEditor(TextEditor *editor);
//    void connectMenuBarToEditor(TextEditor *editor);
 protected:
    Connecter() {};

 private:
    QToolBar *m_toolbar = Q_NULLPTR;
//    QMenuBar *m_menubar = Q_NULLPTR;
};
