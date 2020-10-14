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
    QStringList fonts;
    fonts << "Arial" << "Some font1" << "Some font2";
    ui->comboBox->addItems(fonts);
}

void Preferences::setSizeFont() {
    QStringList sizes;
    sizes << "10" << "12" << "14" << "16" << "18";
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

