#include "mainwindow.h"
#include "tabchanger.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    Connecter::instance().setToolbar(ui->toolBar);
//    Connecter::instance().setMenuBar(ui->menubar);
//    Connecter::instance().connectMenuBarToEditor(nullptr);

    // Dirmodel for file system
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

void MainWindow::on_actionOpen_File_triggered() {
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "/home");
    auto *ffile = new QFile(file);
    ui->widget->AddPageToLastFocus(file.remove(0, file.lastIndexOf('/') + 1), ffile);
}

void MainWindow::on_actionOpen_Folder_triggered() {
    QString dir = QFileDialog::getExistingDirectory(this, "Open Directory", "/home",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    auto index = dynamic_cast<QFileSystemModel *>(ui->treeView->model())->index(dir);
    ui->treeView->setRootIndex(index);
}

void MainWindow::on_actionSettings_triggered() {
    QMessageBox::about(this, "", "settings");
}
