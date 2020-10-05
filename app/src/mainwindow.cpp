#include "mainwindow.h"
#include "tabchanger.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    auto layout = ui->splitter->findChild<EmptyWidget *>()->layout();
    Connecter::instance().setToolbar(ui->toolBar);
    layout->addWidget(new TabChanger);
    layout->addWidget(new TabChanger);
}

MainWindow::~MainWindow() {
    delete ui;
}
