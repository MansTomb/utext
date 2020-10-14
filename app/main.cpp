#include "mainwindow.h"

#include <QApplication>
#include <QDebug>
#include <QtWidgets/QStyleFactory>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    QApplication::setOrganizationName("uText");
    QApplication::setApplicationName("uText");

    QPalette pall;
    QFile File(":/qmain.qss");
    File.open(QFile::ReadOnly);
    QString StyleSheet;
    MainWindow w("uText", 0);

    pall.setColor(w.backgroundRole(), Qt::black);
    StyleSheet = QLatin1String(File.readAll());
    a.setStyleSheet(StyleSheet);

    w.setPalette(pall);
    w.setAutoFillBackground(true);
    w.show();

    return a.exec();
}
