#include "tabchanger.h"
#include "texteditor.h"
#include "emptywidget.h"

#include <QDebug>
#include <QMenu>
#include <QSignalMapper>

TabChanger::TabChanger(int x, int y, QWidget *parent) : m_x(x), m_y(y), QTabWidget(parent) {
    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    setAcceptDrops(true);
    connect(this, &TabChanger::customContextMenuRequested, this, &TabChanger::ShowContextMenu);
}

void TabChanger::dragEnterEvent(QDragEnterEvent *event) {
    event->acceptProposedAction();
}

void TabChanger::dragMoveEvent(QDragMoveEvent *event) {
    event->accept();
}

void TabChanger::dragLeaveEvent(QDragLeaveEvent *event) {
    event->accept();
}

void TabChanger::dropEvent(QDropEvent *event) {
    qDebug() << event->pos().x() << " " << event->pos().y() << " TabChanger";
}

void TabChanger::ShowContextMenu(const QPoint& pos) {
    QMenu contextMenu(tr("Context menu"), this);
    QAction action1("Split Horizontaly", this);
    QAction action2("Split Verticaly", this);

    contextMenu.addAction(&action1);
    connect(&action1, &QAction::triggered, this, [=] {SplitHorizontaly(m_x + 1, m_y);});
    contextMenu.addAction(&action2);
    connect(&action2, &QAction::triggered, this, [=] {SplitVerticaly(m_x, m_y + 1);});


    contextMenu.exec(mapToGlobal(pos));
}

int TabChanger::y() {
    return m_y;
}

int TabChanger::x() {
    return m_x;
}

void TabChanger::AddPage(QString label, QFile *file) {
    TextEditor *editor = new TextEditor(file);

    connect(editor, &TextEditor::InFocus, this, [=]{TabFocused(this);});
    insertTab(0, editor, label);
    setCurrentIndex(0);
}
