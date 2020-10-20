#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QtWidgets/QStyleFactory>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setOrganizationName("uText");
    QApplication::setApplicationName("uText");

    MainWindow w("uText", 0);
    w.setAutoFillBackground(true);
    w.show();

    system("leaks -q utext");
    a.exec();
    system("leaks -q utext");

    return 1;
}
