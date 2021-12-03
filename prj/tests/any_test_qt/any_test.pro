#
# File crash_investigateor.pro
# File created : 18 Nov 2021
# Created by : Davit Kalantaryan (davit.kalantaryan@desy.de)
# This file can be used to produce Makefile for daqadcreceiver application
# for PITZ
# CONFIG += 2test

#QMAKE_CXXFLAGS += "-include types.h"
#DEFINES += u_int=unsigned

#DEFINES += DEBUG_APP

#DEFINES += CRASH_INVEST_DO_NOT_USE_MAL_FREE

win32{
	SOURCES += \
} else {
        GCCPATH = $$system(which g++)
        message("!!!!!!!!!!! GPPPATH=$$GCCPATH")
	SOURCES += \
}

include("$${PWD}/../../common/common_qt/sys_common.pri")
#include("$${PWD}/../../core/core_qt/crash_investigator.pri")

CR_INV_HEADERS_HPP02	= $$cpputilsFindFilesRecursive($${PWD}/../../../src/include, .hpp)

QT -= core
QT -= gui
CONFIG -= qt

INCLUDEPATH += $${PWD}/../../../include
INCLUDEPATH += $${PWD}/../../../src/include

HEADERS += $${CR_INV_HEADERS_HPP02}

SOURCES += "$${PWD}/../../../src/cpputilsm/cpputilsm_memorypool.cpp"
SOURCES += \
	"$${PWD}/../../../src/tests/main_any_test.cpp"
