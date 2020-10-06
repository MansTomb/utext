#include "mainwindow.h"
#include "tabchanger.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    auto whandler = ui->splitter->findChild<EmptyWidget *>();
    Connecter::instance().setToolbar(ui->toolBar);
    whandler->addNewWindow(new TabChanger(0, 0));


    //* Dirmodel for file system
    m_dirmodel = new QFileSystemModel(this);
    m_dirmodel->setRootPath("/");

    //Отображение file system
    ui->treeView->setModel(m_dirmodel);
    for (int i = 1; i < m_dirmodel->columnCount(); ++i) {
        ui->treeView->hideColumn(i);
    }
}

MainWindow::~MainWindow() {
    delete ui;
}
