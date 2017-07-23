TEMPLATE = app

QT += qml quick widgets
CONFIG += c++11

SOURCES += main.cpp \
    filemanager.cpp \
    cpuinfo.cpp \
    infomanager.cpp \
    cpulist.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    filemanager.h \
    cpuinfo.h \
    infomanager.h \
    constantslist.h \
    cpulist.h

