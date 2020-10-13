set(SOURCES mainwindow.cpp mainwindow.ui mainwindow.h
        tabchanger.cpp tabchanger.h
        projectview.cpp projectview.h
        texteditor.cpp texteditor.h
        emptywidget.cpp emptywidget.h
        Connecter.cpp Connecter.h
    preferences.ui preferences.cpp preferences.h
    settingsUtext.cpp settingsUtext.h)

add_library(src ${SOURCES})
target_link_libraries(src PRIVATE Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Gui
)
