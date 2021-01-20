#-------------------------------------------------
#
# Project created by QtCreator 2021-01-17T22:15:16
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = raytracer
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp

HEADERS  += mainwindow.h

FORMS    += mainwindow.ui
QMAKE_CXXFLAGS += -std=c++11

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../libRaytracer/lib/release/ -lraytracer
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../libRaytracer/lib/debug/ -lraytracer
else:unix: LIBS += -L$$PWD/../libRaytracer/lib/ -lraytracer

INCLUDEPATH += $$PWD/../libRaytracer/inc
DEPENDPATH += $$PWD/../libRaytracer/inc

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libRaytracer/lib/release/libraytracer.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libRaytracer/lib/debug/libraytracer.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../libRaytracer/lib/release/raytracer.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../libRaytracer/lib/debug/raytracer.lib
else:unix: PRE_TARGETDEPS += $$PWD/../libRaytracer/lib/libraytracer.a
