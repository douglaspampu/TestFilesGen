TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    arquivoentrada.cpp \
    ../GeradorStrings/GeradorStrings/regex.cpp \
    ../GeradorStrings/GeradorStrings/operacao.cpp \
    ../GeradorStrings/GeradorStrings/operacao_ponto.cpp \
    ../GeradorStrings/GeradorStrings/operador_string.cpp \
    ../GeradorStrings/GeradorStrings/set.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arquivoentrada.h \
    ../GeradorStrings/GeradorStrings/regex.h \
    ../GeradorStrings/GeradorStrings/operacao.h \
    ../GeradorStrings/GeradorStrings/operacao_ponto.h \
    ../GeradorStrings/GeradorStrings/operador_string.h \
    ../GeradorStrings/GeradorStrings/set.h

