#include "mainwindow.h"
#include "tabchanger.h"
#include "preferences.h"

MainWindow::MainWindow(QString name, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("uText");
    settings = new QSettings(QCoreApplication::applicationDirPath() + "/res/settings/settingsUtext.ini", QSettings::IniFormat, this);
    setObjectName(name);
    setWindowTitle(name);
    loadSettings();

    Connecter::instance().setToolbar(ui->toolBar);

    // Dirmodel for file system
    m_dirmodel = new QFileSystemModel(this);
    m_dirmodel->setRootPath("/");

    //Отображение file system
    ui->treeView->setModel(m_dirmodel);
    for (int i = 1; i < m_dirmodel->columnCount(); ++i) {
        ui->treeView->hideColumn(i);
    }

//код прячет первый сплитер, который у нас пустой изначально))
//    ui->splitter->setStyleSheet("QTabBar {\n"
//                                               "background-color: transparent;\n"
//                                               "qproperty-drawBase:0;\n"
//                                               "}");
}

MainWindow::~MainWindow() {
    saveSettings();
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
    auto *preferences = new Preferences;
    preferences->exec();
}

void MainWindow::loadSettings() {
    settings->beginGroup("MainWindow");
    setGeometry(settings->value("geometry", QRect(1000, 1000, 1000, 1000)).toRect());
    settings->endGroup();
}

void MainWindow::saveSettings() {
    settings->beginGroup("MainWindow");
    settings->setValue("geometry", geometry());
    settings->endGroup();
}
