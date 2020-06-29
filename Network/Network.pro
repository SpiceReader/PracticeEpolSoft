CONFIG -= qt

TEMPLATE = lib
CONFIG += staticlib

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

HEADERS += \
    include/INetworkMessage.h \
    include/Request/DeleteTaskArguments.h \
    include/Request/Request.h \
    include/Request/CreateTaskArguments.h \
    include/Request/UpdateTaskArguments.h \
    include/Response/Response.h\
    include/Task/Task.h

SOURCES += \
    source/Request/DeleteTaskArguments.cpp \
    source/Request/UpdateTaskArguments.cpp \
    source/Request/CreateTaskArguments.cpp \
    source/INetworkMessage.cpp \
    source/Request/CreateTaskArguments.cpp \
    source/Request/Request.cpp \
    source/Response/Response.cpp\
    source/Task/Task.cpp

INCLUDEPATH += include/

CONFIG += conan_basic_setup
include(../Libs/Conan/conanbuildinfo.pri)

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Default rules for deployment.

TARGET = LibNetwork

DESTDIR = $$shell_path($$_PRO_FILE_PWD_)/lib
