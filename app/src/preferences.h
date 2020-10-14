#ifndef PREFERENCES_H
#define PREFERENCES_H

#include <QDialog>

namespace Ui {
class Preferences;
};

class Preferences : public QDialog {
 Q_OBJECT

 public:
    explicit Preferences(QWidget *parent = nullptr);
    ~Preferences() override;
 signals:

 private:
    void setFont();
    void setSizeFont();
    void setThema();
    void setLanguage();
    Ui::Preferences *ui;
};

#endif
