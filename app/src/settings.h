#pragma once

#include <QDebug>

#include <QMap>
#include <QString>
#include <QVector>
#include <QSettings>
#include <QFontDatabase>
#include <QCoreApplication>
#include "texteditor.h"

class Settings {
 public:
    Settings();
    QMap<QString, QString> &getPreferences();
    QSettings *getSettings();
    void setPreferences(const QMap<QString, QString> &preferences);
    void applySettingsToEditor(TextEditor *editor);
    void applyTheme(const QString &nameTheme);
    void checkValidPreferences();

 private:
    QSettings *m_settings;
    QMap<QString, QString> m_preferences;
    QMap<QString, QStringList> m_allSettings;
};
