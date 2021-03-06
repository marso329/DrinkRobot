QT += core gui widgets sql multimedia qml quick  

TARGET = template
TEMPLATE = app

CONFIG += qt
CONFIG += no_keywords
CONFIG += disable-desktop
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT
static {
    QT += svg
    QTPLUGIN += qtvirtualkeyboardplugin
}


QMAKE_CXXFLAGS += -g -std=c++17 -pedantic -Werror -Wall

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
		$$SRCDIR/database.cpp \
				$$SRCDIR/itemdelegate.cpp \
		$$SRCDIR/temperature_controller.cpp \
				$$SRCDIR/hardware.cpp \
		$$SRCDIR/startscreen.cpp	

HEADERS +=	$$INCLUDEDIR/mainwindow.h \
			$$INCLUDEDIR/statemachine.h \
			$$INCLUDEDIR/database.h \
			$$INCLUDEDIR/tuple.h \
			$$INCLUDEDIR/itemdelegate.h \
			$$INCLUDEDIR/type_traits.h \
			$$INCLUDEDIR/temperature_controller.h \
			$$INCLUDEDIR/hardware.h \
			$$INCLUDEDIR/startscreen.h

INCLUDEPATH +=./$${INCLUDEDIR}

LIBS += -lboost_serialization -lboost_thread -lboost_system  -lboost_filesystem

FORMS += ../ui/mainwindow.ui \
		../ui/iconselector.ui \
				../ui/loading.ui \
		../ui/password.ui


RESOURCES += $$RESOURCEDIR/resources.qrc \
		$$RESOURCEDIR/resources1.qrc
