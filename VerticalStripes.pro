CONFIG += static
TEMPLATE = app

QT += qml quick serialport printsupport
CONFIG += c++11


SOURCES += main.cpp \
    rawprinter.cpp

RESOURCES += qml.qrc

LIBS += -lwinspool

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
include(deployment.pri)

HEADERS += \
    rawprinter.h
