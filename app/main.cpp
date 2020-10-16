#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QtWidgets/QStyleFactory>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QApplication::setOrganizationName("uText");
    QApplication::setApplicationName("uText");

//    QFile File(":/qss/Default.qss");
//    File.open(QFile::ReadOnly);
//    QString StyleSheet;
//    StyleSheet = QLatin1String(File.readAll());
//    a.setStyleSheet(StyleSheet);


    MainWindow w("uText", 0);
    w.setAutoFillBackground(true);
    w.show();

    return a.exec();
}
