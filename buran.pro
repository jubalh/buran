#-------------------------------------------------
#
# Project created by QtCreator 2015-08-12T12:13:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = buran
TEMPLATE = app


SOURCES += src/main.cpp\
        src/mainwindow.cpp \
    src/configurationdialog.cpp

HEADERS  += src/mainwindow.h \
    src/configurationdialog.h

FORMS    += src/mainwindow.ui \
    src/configurationdialog.ui

RESOURCES += \
    resources/res.qrc

mac {
    binaries.path = /usr/local/bin
    QMAKE_INFO_PLIST = mac/Info.plist
} else {
    binaries.path = /usr/bin	
}

binaries.files = buran
INSTALLS += binaries
