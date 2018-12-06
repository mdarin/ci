QT += gui \
xml \
    network
CONFIG += console \
designer
DESTDIR = ..
TARGET = {$imitator}
TEMPLATE = lib
CONFIG += dll
HEADERS += virtualwrapper{$imitator}.h \
../../../include/ivirtualwrapper.h
SOURCES += virtualwrapper{$imitator}.cpp
INCLUDEPATH += ../../../include/
INCLUDEPATH += ../../../icore/
INCLUDEPATH += ../../../src/icomponents
INCLUDEPATH += ../../../src/icompsdispatcher
DEFINES += __x86__
unix {
DEFINES += __OS_VERSION__=2 \
    __linux__
OMNIBASE = /usr/local
INCLUDEPATH += /usr/include/omniORB4 \
    /usr/include/COS
LIBS += -L../../lib
MOC_DIR = .moc
OBJECTS_DIR = .obj
}
win32 {
INCLUDEPATH += $$(OMNIORB_BASE)/include/
DEFINES += __WIN32__ \
    WIN32 \
    _WIN32_WINNT=0x0400 \
    __NT__ \
    __OSVERSION__=4
LIBS += -L$$(OMNIORB_BASE)/lib/x86_win32 \
    -lomniDynamic4_rt \
    -lomniORB4_rt \
    -lomnithread_rt
LIBS += ../../../lib/idisp2.lib
MOC_DIR = _moc
OBJECTS_DIR = _obj
}
