
QT += opengl \
    script \
    xml
TARGET = SetViewer
TEMPLATE = app
SOURCES += main.cpp \
    mainwindow.cpp \
    GLWidget.cpp \
    rubics.cpp
HEADERS += mainwindow.h \
    GLWidget.h \
    rubics.h \
    cube.h \
    solutions.h \
    Singmaster.h \
    Oppocross.h
FORMS += mainwindow.ui
LIBS += -lGLU
#QTPLUGIN += qpng

QT += testlib
OTHER_FILES += \
    ../../project/cubestate1.txt
