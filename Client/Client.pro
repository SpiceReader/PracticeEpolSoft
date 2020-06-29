QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Database/dbapi.cpp \
    GUI/mainwindow.cpp \
    MessageHandler/MessageHandler.cpp \
    TaskHandler/SingletonTaskHandler.cpp \
    GUI/dialogconnection.cpp \
    main.cpp

HEADERS += \
    Database/dbapi.h \
    GUI/mainwindow.h \
    MessageHandler/IMessageObserver.h \
    MessageHandler/MessageHandler.h \
    TaskHandler/SingletonTaskHandler.h \
    GUI/dialogconnection.h

FORMS += \
    GUI/mainwindow.ui \
    GUI/dialogconnection.ui

INCLUDEPATH += ../Network/include/
LIBS += -L"$$shell_path($$_PRO_FILE_PWD_)/../Network/lib" -lLibNetwork

CONFIG += conan_basic_setup
include(../Libs/Conan/conanbuildinfo.pri)

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
