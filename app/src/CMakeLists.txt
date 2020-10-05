set(SOURCES mainwindow.cpp mainwindow.ui)

add_library(src ${SOURCES})
target_link_libraries(src PRIVATE Qt${QT_VERSION_MAJOR}::Core
        Qt${QT_VERSION_MAJOR}::Widgets
        Qt${QT_VERSION_MAJOR}::Gui
)
