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
    ~Preferences();
 signals:

 private:
//    QWidget m_parent;
    Ui::Preferences *ui;
};

#endif
