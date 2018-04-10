QT += core gui widgets sql multimedia

TARGET = template
TEMPLATE = app

CONFIG += qt
CONFIG += no_keywords

QMAKE_CXXFLAGS += -g -std=c++11 -pedantic -Werror -Wall

OBJ_DIR = ../build
OBJECTS_DIR = ../build
MOC_DIR = ../build
DESTDIR = ../bin
INCLUDEDIR=../include
SRCDIR=../src
UI_DIR = ../include
RESOURCEDIR=../resources

SOURCES +=	$$SRCDIR/main.cpp \
		$$SRCDIR/mainwindow.cpp \
		$$SRCDIR/statemachine.cpp \
		$$SRCDIR/startscreen.cpp	

HEADERS +=	$$INCLUDEDIR/mainwindow.h \
			$$INCLUDEDIR/statemachine.h \
			$$INCLUDEDIR/startscreen.h

INCLUDEPATH +=./$${INCLUDEDIR}

LIBS += 

FORMS += ../ui/mainwindow.ui


RESOURCES = $$RESOURCEDIR/resources.qrc