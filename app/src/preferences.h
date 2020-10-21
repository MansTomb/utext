#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>
#include <QMap>
#include <QDebug>
#include <QFontDatabase>

namespace Ui {
class Preferences;
};

class Preferences : public QDialog {
 Q_OBJECT
 public:
    explicit Preferences(const QMap<QString, QString> &preferences, QWidget *parent = nullptr);
    ~Preferences() override;
 signals:
    void ReturnValues(QMap<QString, QString> m_preferences);
 private:
    void setFont();
    void setSizeFont();
    void setTheme();
    void setLanguage();
    void accept() override;

    Ui::Preferences *ui;
    QMap<QString, QString> m_preferences;
};

#endif
