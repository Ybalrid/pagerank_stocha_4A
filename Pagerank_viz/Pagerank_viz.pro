#-------------------------------------------------
#
# Project created by QtCreator 2015-11-05T19:04:27
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Pagerank_viz
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    pagegraph.cpp \
    pagenode.cpp \
    pagerankvizwidget.cpp \
    crawler.cpp \
    exploreparam.cpp

HEADERS  += mainwindow.h \
    pagegraph.h \
    pagenode.h \
    pagerankvizwidget.h \
    crawler.h \
    exploreparam.h
