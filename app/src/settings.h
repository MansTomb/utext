#pragma once

#include <QMap>
#include <QString>
#include <QVector>
#include <QSettings>
#include <QFontDatabase>
#include <QCoreApplication>

class Settings {
    public:
    Settings();
    QMap<QString, QString>& getPreferences();
    QSettings* getSettings();
    void setPreferences(const QMap<QString, QString>& preferences);

    private:
    QSettings *m_settings;
    QMap<QString, QString> m_preferences;
    QMap<QString, QStringList> m_allSettings;
};
