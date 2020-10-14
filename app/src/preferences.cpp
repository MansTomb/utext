#include "preferences.h"
#include "ui_preferences.h"

Preferences::Preferences(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Preferences) {
    ui->setupUi(this);
    setObjectName("Preferences");
    setFont();
    setSizeFont();
    setThema();
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

void Preferences::setThema() {
    QStringList themas;
    themas << "Default" << "Light" << "Dark";
    ui->comboBox_3->addItems(themas);
}

void Preferences::setLanguage() {
    QStringList themas;
    themas << "Russian" << "English" << "Ukraine";
    ui->comboBox_4->addItems(themas);
}

