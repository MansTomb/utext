#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>

#include "ui_preferences.h"

namespace Ui {
class Preferences;
};

class Preferences : public QDialog {
 Q_OBJECT

 public:
    explicit Preferences(QWidget *parent = nullptr);
    ~Preferences();
 signals:

 private:
    Ui::Preferences *ui;
};

#endif
