#-------------------------------------------------
#
# Project created by QtCreator 2012-05-26T18:03:43
#
#-------------------------------------------------

QT       += core gui

TARGET = Lucky_OIer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    tabmanager.cpp \
    global.cpp \
    codeeditor.cpp \
    codeeditorconfiger.cpp \
    aboutdialog.cpp \
    qsplashscreenplus.cpp \
    configerbase.cpp

HEADERS  += mainwindow.h \
    lop_plugins_interface.h \
    tabmanager.h \
    global.h \
    codeeditor.h \
    codeeditorconfiger.h \
    aboutdialog.h \
    qsplashscreenplus.h \
    configerbase.h

unix|win32: LIBS += -lqscintilla2

FORMS += \
    codeeditorconfiger.ui \
    aboutdialog.ui \
    tabmanagerconfiger.ui

RESOURCES += \
    Lucky_OIer.qrc

OTHER_FILES += \
    version.txt \
    gpl-3.0.html \
    readme.html \
    authors.txt
