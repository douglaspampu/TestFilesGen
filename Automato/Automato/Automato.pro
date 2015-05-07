TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    estado.cpp \
    automato.cpp \
    regex.cpp \
    set.cpp \
    operacao.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    estado.h \
    automato.h \
    regex.h \
    set.h \
    operacao.h

