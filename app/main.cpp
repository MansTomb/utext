#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QtWidgets/QStyleFactory>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setOrganizationName("uText");
    QApplication::setApplicationName("uText");
    QPalette pall;
    MainWindow w("uText", 0);
    pall.setColor(w.backgroundRole(), Qt::black);
    w.setPalette(pall);
    w.setAutoFillBackground(true);
    w.show();
    return a.exec();
}
