#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    Connecter::instance().setToolbar(ui->toolBar);
    EmptyWidget *text = new EmptyWidget;
    text->addWidgetToLayout(new TextEditor);
    text->addWidgetToLayout(new TextEditor);
    ui->tabWidget->insertTab(0, text, "loh");
    ui->tabWidget->insertTab(0, text, "loh1");
    ui->tabWidget->insertTab(0, text, "loh2");
    ui->tabWidget->insertTab(0, text, "loh3");
}

MainWindow::~MainWindow() {
    delete ui;
}
