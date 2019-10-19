#-------------------------------------------------
#
# Project created by QtCreator 2019-03-24T16:37:43
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets multimedia

TARGET = GNSS-Stylus
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++17

LIBS += -l"ws2_32"

SOURCES += \
    laserrangefinder20hzv2messagemonitorform.cpp \
    laserrangefinder20hzv2serialthread.cpp \
        main.cpp \
        mainwindow.cpp \
    gnssmessage.cpp \
    ntripthread.cpp \
    ubloxdatastreamprocessor.cpp \
    serialthread.cpp \
    messagemonitorform.cpp \
    relposnedform.cpp \
    essentialsform.cpp \
    rightclickpushbutton.cpp \
    postprocessform.cpp

HEADERS += \
    laserrangefinder20hzv2messagemonitorform.h \
    laserrangefinder20hzv2serialthread.h \
        mainwindow.h \
    gnssmessage.h \
    ntripthread.h \
    ubloxdatastreamprocessor.h \
    serialthread.h \
    messagemonitorform.h \
    relposnedform.h \
    essentialsform.h \
    rightclickpushbutton.h \
    postprocessform.h

FORMS += \
    laserrangefinder20hzv2messagemonitorform.ui \
        mainwindow.ui \
    messagemonitorform.ui \
    relposnedform.ui \
    essentialsform.ui \
    postprocessform.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
