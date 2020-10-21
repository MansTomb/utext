#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWidgets/QTableWidgetItem>
#include <QtWidgets/QDialog>
#include <QtWidgets/QStyleFactory>
#include <QLineEdit>
#include <QFileSystemModel>
#include <QFileDialog>
#include <QMessageBox>
#include <QSettings>
#include <QFontDatabase>

#include "ui_mainwindow.h"
#include "texteditor.h"
#include "emptywidget.h"
#include "Connecter.h"
#include "settings.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
 Q_OBJECT

 public:
    MainWindow(const QString &name, QWidget *parent = nullptr);
    ~MainWindow();

 private slots:
    void on_actionOpen_File_triggered();
    void on_actionOpen_Folder_triggered();
    void on_actionSettings_triggered();
    void ProcessPreferences(const QMap<QString, QString> &preferences);
    void SaveAllFiles();

 private:
    void initSettings();
    void loadSettings();
    void saveSettings();
 protected:
    void closeEvent(QCloseEvent *event) override;
 private:
    Ui::MainWindow *ui;
    QFileSystemModel *m_dirmodel;
    QMap<QString, QString> m_preferences;
    Settings *preferences;
    QSettings *settings;
};

#endif // MAINWINDOW_H
