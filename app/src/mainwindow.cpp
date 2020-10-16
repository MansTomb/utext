#include "mainwindow.h"
#include "tabchanger.h"
#include "preferences.h"

MainWindow::MainWindow(const QString& name, QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->setWindowTitle("uText");
    setObjectName(name);
    setWindowTitle(name);

    //Preferences
    preferences = new Settings;
    preferences->applyTheme(preferences->getPreferences()["theme"]);
    initSettings();
    loadSettings();

    //ToolBar
    Connecter::instance().setToolbar(ui->toolBar);

    // Dirmodel for file system
    m_dirmodel = new QFileSystemModel(this);
    m_dirmodel->setRootPath("/");

    //View file system
    ui->treeView->setModel(m_dirmodel);
    for (int i = 0; i < m_dirmodel->columnCount(); ++i) {
        ui->treeView->hideColumn(i);
    }
    ui->treeView->setHeaderHidden(true);
    ui->textEdit->setHidden(true);
}

MainWindow::~MainWindow() {
    saveSettings();
    delete settings;
    delete ui;
    system("leaks -q utext");
}

void MainWindow::on_actionOpen_File_triggered() {
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"), "/home");
    if (!file.isEmpty()) {
        auto *ffile = new QFile(file);
        ui->widget->AddPageToLastFocus(file.remove(0,file.lastIndexOf('/') + 1), ffile);
    }
}

void MainWindow::on_actionOpen_Folder_triggered() {
    QString dir = QFileDialog::getExistingDirectory(this, "Open Directory", "/home",
                                                    QFileDialog::ShowDirsOnly | QFileDialog::DontResolveSymlinks);
    if (!dir.isEmpty()) {
        auto index =
            dynamic_cast<QFileSystemModel *>(ui->treeView->model())->index(dir);
        ui->treeView->setRootIndex(index);
        ui->treeView->showColumn(0);
    }
}

void MainWindow::on_actionSettings_triggered() {
    auto *preferencesDialog = new Preferences(preferences->getPreferences());
    QObject::connect(preferencesDialog, &Preferences::ReturnValues,
                     this, &MainWindow::ProcessPreferences);
    preferencesDialog->exec();
}

void MainWindow::loadSettings() {
    settings->beginGroup("MainWindow");
    setGeometry(settings->value("geometry", QRect(1000, 1000, 1000, 1000)).toRect());
    settings->endGroup();
}

void MainWindow::saveSettings() {
    auto tmp_preferences = preferences->getPreferences();
    auto tmp_settings = preferences->getSettings();

    tmp_settings->beginGroup("MainWindow");
    tmp_settings->setValue("geometry", geometry());
    tmp_settings->endGroup();
    tmp_settings->beginGroup("Preferences");
    tmp_settings->setValue("font", tmp_preferences["font"]);
    tmp_settings->setValue("size_font", tmp_preferences["size_font"]);
    tmp_settings->setValue("theme", tmp_preferences["theme"]);
    tmp_settings->setValue("language", tmp_preferences["language"]);
    tmp_settings->endGroup();
}

void MainWindow::ProcessPreferences(const QMap<QString, QString>& preferencesDialog) {
    preferences->setPreferences(preferencesDialog);
    saveSettings();
    preferences->applyTheme(preferencesDialog["theme"]);
    for (auto &item : findChildren<TextEditor *>()) {
        QFont font(preferencesDialog["font"]);
        font.setPointSize(preferencesDialog["size_font"].toInt());
        item->setFont(font);
    }
}

void MainWindow::initSettings() {
    settings = preferences->getSettings();
}

void MainWindow::closeEvent(QCloseEvent *event) {
    for (const auto &item : findChildren<TextEditor *>())
        item->SaveAtExit();

    QWidget::closeEvent(event);
}

void MainWindow::SaveAllFiles() {
    for (const auto &item : findChildren<TextEditor *>())
        item->Save();
}
