#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QDialog>
#include <QtWidgets/QStyleFactory>
#include <QLineEdit>

#include "ui_mainwindow.h"
#include "texteditor.h"
#include "emptywidget.h"
#include "Connecter.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
