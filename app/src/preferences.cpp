#include "preferences.h"
#include "ui_preferences.h"

#include <QMessageBox>

Preferences::Preferences(const QMap<QString, QString>& preferences, QWidget *parent) :
    QDialog(parent), ui(new Ui::Preferences), m_preferences(preferences) {
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
    QStringList list = db.families();

    ui->comboBox->addItems(list);
    ui->comboBox->setCurrentIndex(list.indexOf(m_preferences["font"]));
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
    ui->comboBox_2->setCurrentIndex(sizes.indexOf(m_preferences["size_font"]));
}

void Preferences::setTheme() {
    QStringList themes;
    themes << "Default" << "Light" << "Dark";
    ui->comboBox_3->addItems(themes);
    ui->comboBox_2->setCurrentIndex(themes.indexOf(m_preferences["theme"]));
}

void Preferences::setLanguage() {
    QStringList languages;
    languages << "Russian" << "English" << "Ukraine";
    ui->comboBox_4->addItems(languages);
    ui->comboBox_2->setCurrentIndex(languages.indexOf(m_preferences["language"]));
}

void Preferences::accept() {
    m_preferences["font"] = ui->comboBox->currentText();
    m_preferences["size_font"] = ui->comboBox_2->currentText();
    m_preferences["theme"] = ui->comboBox_3->currentText();
    m_preferences["language"] = ui->comboBox_4->currentText();
    emit ReturnValues(m_preferences);
    QDialog::accept();
}

