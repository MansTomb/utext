#pragma once

#include <QWidget>
#include <QTabWidget>
#include <QTreeView>

class ProjectView : public QTreeView {
 Q_OBJECT

 public:
    explicit ProjectView(QWidget *parent = Q_NULLPTR);
 protected:

};
