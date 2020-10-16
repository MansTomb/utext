#include "treeviewcontextdialog.h"
#include "ui_treeviewcontextdialog.h"

#include <QMessageBox>

TreeViewContextDialog::TreeViewContextDialog(QWidget *parent) : QDialog(parent), ui(new Ui::TreeViewContextDialog) {
    ui->setupUi(this);
    ui->edit->setPlaceholderText("Write file/folder name here");
}

TreeViewContextDialog::~TreeViewContextDialog() {
    delete ui;
}

void TreeViewContextDialog::accept() {
    if (!ui->edit->text().isEmpty()) {
        QDialog::accept();
        return;
    }
    QMessageBox msg;
    msg.setText("Field cant be empty!");
    msg.exec();
}
QLineEdit *TreeViewContextDialog::getEdit() {
    return ui->edit;
}

