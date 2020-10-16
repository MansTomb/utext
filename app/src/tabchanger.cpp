#include "tabchanger.h"
#include "texteditor.h"
#include "emptywidget.h"
#include "editorlayout.h"

#include <QDebug>
#include <QMenu>
#include <QSignalMapper>
#include <QFileInfo>

TabChanger::TabChanger(int x, int y, QWidget *parent) : m_x(x), m_y(y), QTabWidget(parent) {
    setContextMenuPolicy(Qt::ContextMenuPolicy::CustomContextMenu);
    setAcceptDrops(true);
    setDocumentMode(true);
    setTabsClosable(true);
    setMovable(true);
    connect(this, &TabChanger::tabCloseRequested, this, &TabChanger::CloseTab);
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
    if (!event->mimeData()->hasUrls())
        return;
    auto files = event->mimeData()->urls();

    for (const auto &file : files) {
        QFileInfo finfo(file.toString().remove(0, 7));
        if (finfo.isFile())
            AddPage(finfo.fileName(), new QFile(finfo.absoluteFilePath()));
    }
}

void TabChanger::ShowContextMenu(const QPoint& pos) {
    QMenu contextMenu(tr("Context menu"), this);
    QAction action1("Split Horizontaly", this);
    QAction action2("Split Verticaly", this);

    contextMenu.addAction(&action1);
    connect(&action1, &QAction::triggered, this, [=] { SplitHorizontaly(m_x + 1, m_y, dynamic_cast<EditorLayout *>(currentWidget())->editor());});
    contextMenu.addAction(&action2);
    connect(&action2, &QAction::triggered, this, [=] { SplitVerticaly(m_x, m_y + 1, dynamic_cast<EditorLayout *>(currentWidget())->editor());});

    contextMenu.exec(mapToGlobal(pos));
}

int TabChanger::y() {
    return m_y;
}

int TabChanger::x() {
    return m_x;
}

void TabChanger::AddPage(QString label, QFile *file) {
    auto editorLayout = new EditorLayout(file);

    for (const auto &item : findChildren<TextEditor *>()) {
        if (dynamic_cast<TextEditor *>(item)->file()->fileName() == file->fileName()) {
            setCurrentWidget(item->parentWidget());
            return;
        }
    }
    connect(editorLayout->editor(), &TextEditor::InFocus, this, [=]{emit TabFocused(this);});
    insertTab(0, editorLayout, label);
    setCurrentIndex(0);
}

void TabChanger::AddPage(QWidget *editor) {
    auto editorLayout = new EditorLayout(dynamic_cast<TextEditor *>(editor)->file());

    connect(editorLayout->editor(), &TextEditor::InFocus, this, [=]{emit TabFocused(this);});
    insertTab(0, editorLayout, editorLayout->file()->fileName().remove(0, editorLayout->file()->fileName().lastIndexOf('/') + 1));
}

void TabChanger::CloseTab(int index) {
    auto editor = widget(index);
    removeTab(index);
    delete editor;
}
