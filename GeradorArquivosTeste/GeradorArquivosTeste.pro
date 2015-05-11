TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    arquivoentrada.cpp \
    ../GeradorStrings/GeradorStrings/regex.cpp

include(deployment.pri)
qtcAddDeployment()

HEADERS += \
    arquivoentrada.h \
    ../GeradorStrings/GeradorStrings/regex.h

