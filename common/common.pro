######################################################################
# Automatically generated by qmake (2.01a) sob. wrz 27 17:44:38 2008
######################################################################

TEMPLATE = lib
TARGET = flyercommon
CONFIG += staticlib \
 opengl \
 debug
DESTDIR = ../lib

# Input
HEADERS += activeattachpoint.h \
           airfield.h \
           antiairgunoperator.h \
           attachpoint.h \
           autopilot.h \
           b2dqt.h \
           body.h \
           bodyprovider.h \
           building.h \
           bullet.h \
           cloud.h \
           contactfuse.h \
           controlsurface.h \
           damagemanager.h \
           engine.h \
           environment.h \
           explosion.h \
           gexception.h \
           ground.h \
           gun.h \
           joint.h \
           landinglight.h \
           machine.h \
           mounting.h \
           passiveattachpoint.h \
           plane.h \
           renderingoptions.h \
           serializable.h \
           shape.h \
           shrapnel.h \
           spotlight.h \
           surface.h \
           system.h \
           texture.h \
           textureprovider.h \
           wheelbrake.h \
           wing.h \
           world.h \
           worldobject.h \
           objects/ironbomb.h \
           objects/antiairbattery.h \
           objects/planebumblebee.h \
 common.h \
 grounddecoration.h \
 hangar.h \
 message.h \
 physicalobject.h \
 pilot.h


SOURCES += activeattachpoint.cpp \
           airfield.cpp \
           antiairgunoperator.cpp \
           attachpoint.cpp \
           autopilot.cpp \
           b2dqt.cpp \
           body.cpp \
           bodyprovider.cpp \
           building.cpp \
           bullet.cpp \
           cloud.cpp \
           contactfuse.cpp \
           controlsurface.cpp \
           damagemanager.cpp \
           engine.cpp \
           environment.cpp \
           explosion.cpp \
           ground.cpp \
           gun.cpp \
           joint.cpp \
           landinglight.cpp \
           machine.cpp \
           mounting.cpp \
           passiveattachpoint.cpp \
           plane.cpp \
           renderingoptions.cpp \
           serializable.cpp \
           shape.cpp \
           shrapnel.cpp \
           spotlight.cpp \
           surface.cpp \
           system.cpp \
           texture.cpp \
           textureprovider.cpp \
           wheelbrake.cpp \
           wing.cpp \
           world.cpp \
           worldobject.cpp \
           objects/ironbomb.cpp \
           objects/antiairbattery.cpp \
           objects/planebumblebee.cpp \
 grounddecoration.cpp \
 hangar.cpp \
 message.cpp \
 common.cpp \
 physicalobject.cpp \
 pilot.cpp


QT += opengl

CONFIG -= release

INCLUDEPATH += ../gpc \
  ../include \
  objects

LIBS += ../lib/libgpc.a \
  -L../lib \
  -lbox2d

TARGETDEPS += ../lib/libgpc.a

