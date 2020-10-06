#include "mainwindow.h"
#include "tabchanger.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    auto whandler = ui->splitter->findChild<EmptyWidget *>();
    Connecter::instance().setToolbar(ui->toolBar);
    whandler->addNewWindow(new TabChanger(0, 0));
}

MainWindow::~MainWindow() {
    delete ui;
}
