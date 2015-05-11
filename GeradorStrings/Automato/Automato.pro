TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    estado.cpp \
    automato.cpp \
    regex.cpp \
    set.cpp \
    operacao.cpp \
    operador_or.cpp \
    operador_string.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    estado.h \
    automato.h \
    regex.h \
    set.h \
    operacao.h \
    operador_or.h \
    operador_string.h

