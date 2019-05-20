# This file is generated automatically. Do not edit.
# Use project properties -> Build -> Qt -> Expert -> Custom Definitions.
TEMPLATE = app
DESTDIR = dist/Release/MinGW_QT-Windows
TARGET = 1-CADRE_QT
VERSION = 1.0.0
CONFIG -= debug_and_release app_bundle lib_bundle
CONFIG += release 
PKGCONFIG +=
QT = core gui widgets
SOURCES += 1-CADRE_QT.cpp C_CADRE.cpp C_CLIENT.cpp C_INFO.cpp C_MUTEX.cpp C_SERVEUR.cpp C_THREAD.cpp
HEADERS += C_CADRE.h C_CLIENT.h C_INFO.h C_MUTEX.h C_SERVEUR.h C_THREAD.h
FORMS += C_CADRE.ui
RESOURCES +=
TRANSLATIONS +=
OBJECTS_DIR = build/Release/MinGW_QT-Windows
MOC_DIR = 
RCC_DIR = 
UI_DIR = 
QMAKE_CC = gcc
QMAKE_CXX = g++
DEFINES += 
INCLUDEPATH += 
LIBS += 
