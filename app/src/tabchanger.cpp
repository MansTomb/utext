#include "tabchanger.h"
#include "texteditor.h"

#include <QDebug>

TabChanger::TabChanger(QWidget *parent) : QTabWidget(parent) {
    insertTab(0, new TextEditor, "Log");
}
