#include "preferences.h"
#include "ui_preferences.h"

#include <QMessageBox>

Preferences::Preferences(QWidget *parent) :
    QDialog(parent), ui(new Ui::Preferences) {
    ui->setupUi(this);
    setObjectName("Preferences");
    setFont();
    setSizeFont();
    setTheme();
    setLanguage();
}

Preferences::~Preferences() {
    delete ui;
}

void Preferences::setFont() {
    QFontDatabase db;
    ui->comboBox->addItems(db.families());
}

void Preferences::setSizeFont() {
    QStringList sizes;
    for(int i = 5; i < 99; i++) {
        if (i > 30) {
            i += 2;
        }
        sizes << QString::number(i);
    }
    ui->comboBox_2->addItems(sizes);
}

void Preferences::setTheme() {
    QStringList themes;
    themes << "Default" << "Light" << "Dark";
    ui->comboBox_3->addItems(themes);
}

void Preferences::setLanguage() {
    QStringList themas;
    themas << "Russian" << "English" << "Ukraine";
    ui->comboBox_4->addItems(themas);
}

void Preferences::accept() {
    m_preferences["font"] = ui->comboBox->currentText();
    m_preferences["size_font"] = ui->comboBox_2->currentText();
    m_preferences["theme"] = ui->comboBox_3->currentText();
    m_preferences["language"] = ui->comboBox_4->currentText();
    emit ReturnValues(m_preferences);
    QDialog::accept();
}

