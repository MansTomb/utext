#pragma once

#include <QDialog>
#include <QMap>
#include <QDebug>
#include <QFontDatabase>
#include <QErrorMessage>
#include <QLineEdit>

namespace Ui {
    class TreeViewContextDialog;
};

class TreeViewContextDialog : public QDialog {
 Q_OBJECT
 public:
    explicit TreeViewContextDialog(QWidget *parent = nullptr);
    ~TreeViewContextDialog() override;
    QLineEdit *getEdit();
 private:
    void accept() override;

    Ui::TreeViewContextDialog *ui;
};
