TARGET = {$imitator}
DESTDIR = ..
TEMPLATE = lib
CONFIG += dll
DEFINES += MYSHAREDLIB_LIBRARY
QT += xml \
    gui \
    svg
CONFIG += designer # console
INCLUDEPATH += ../../src/icomponents
SOURCES += {$imitator}.cpp

# main.cpp
HEADERS += {$imitator}.h
FORMS += {$imitator}.ui
win32 {
    LIBS += ..\..\lib\icomponents.lib
    LIBS += ..\..\lib\idisp2.lib
}
unix {
    LIBS += -L../../lib/ \ 
        -licomponents
    LIBS += -L../../lib/ \ 
        -lidisp
}
