#include "settings.h"

Settings::Settings() {
    QFontDatabase db;
    QStringList sizes;
    QStringList themes;
    QStringList languages;
    m_settings = new QSettings(QCoreApplication::applicationDirPath() + "/app/res/settings/settingsUtext.ini",
                               QSettings::IniFormat);

    for(int i = 5; i < 99; i++) {
        if (i > 30) {
            i += 2;
        }
        sizes << QString::number(i);
    }
    m_allSettings["font"] = db.families();
    m_allSettings["size"] = sizes;
    m_allSettings["theme"] = themes << "Default" << "Light" << "Dark";
    m_allSettings["language"] = languages << "English" << "Russian" << "Ukraine";

    m_preferences["font"] = m_settings->value("font", "Tahoma").toString();
    m_preferences["size_font"] = m_settings->value("size_font", 10).toString();
    m_preferences["theme"] = m_settings->value("theme", "Default").toString();
    m_preferences["language"] = m_settings->value("language", "English").toString();
}

QMap<QString, QString> &Settings::getPreferences() {
    return m_preferences;
}
QSettings *Settings::getSettings() {
    return m_settings;
}
void Settings::setPreferences(const QMap<QString, QString>& preferences) {
    m_preferences.insert(preferences);
}
