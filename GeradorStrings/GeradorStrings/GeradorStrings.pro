TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    operacao.cpp \
    operador_string.cpp \
    regex.cpp \
    set.cpp \
    operacao_ponto.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    operacao.h \
    operador_string.h \
    regex.h \
    set.h \
    operacao_ponto.h

