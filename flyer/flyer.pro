######################################################################
# Automatically generated by qmake (2.01a) sob. wrz 27 17:50:22 2008
######################################################################

TEMPLATE = app
TARGET = flyer
DEPENDPATH += .
QT += opengl
DESTDIR = ../bin

# Input
HEADERS += mainwindow.h statuswindow.h worldwidget.h \
 worldscene.h \
 game.h \
 gameui.h \
 gameuidialog.h \
 gameuimain.h
FORMS += mainwindow.ui statuswindow.ui \
 gameuimain.ui
SOURCES += main.cpp mainwindow.cpp statuswindow.cpp worldwidget.cpp \
 worldscene.cpp \
 game.cpp \
 gameui.cpp \
 gameuidialog.cpp \
 gameuimain.cpp

TARGETDEPS += ../lib/libflyercommon.a

CONFIG -= release

CONFIG += debug

INCLUDEPATH += ../common \
  ../common/objects/ \
  ../include

LIBS += -L../lib \
  -lflyercommon \
  -lgpc \
  -lbox2d

