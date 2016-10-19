#-------------------------------------------------
#
# Project created by QtCreator 2015-08-12T12:13:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = buran
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    configurationdialog.cpp

HEADERS  += mainwindow.h \
    configurationdialog.h

FORMS    += mainwindow.ui \
    configurationdialog.ui

RESOURCES += \
    res.qrc

mac {
    binaries.path = /usr/local/bin
    QMAKE_INFO_PLIST = Info.plist
} else {
    binaries.path = /usr/bin	
}

binaries.files = buran
INSTALLS += binaries
