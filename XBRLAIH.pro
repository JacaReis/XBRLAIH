#***************************************************************************************
# Copyright (c) 2012 Lucas Lira Gomes <x8lucas8x@gmail.com>                            *
# Copyright (c) 2012 Raony Benjamim <raonybenjamim@gmail.com>                          *
#                                                                                      *
# This program is free software; you can redistribute it and/or modify it under        *
# the terms of the GNU General Public License as published by the Free Software        *
# Foundation; either version 2 of the License, or (at your option) any later           *
# version.                                                                             *
#                                                                                      *
# This program is distributed in the hope that it will be useful, but WITHOUT ANY      *
# WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A      *
# PARTICULAR PURPOSE. See the GNU General Public License for more details.             *
#                                                                                      *
# You should have received a copy of the GNU General Public License along with         *
# this program.  If not, see <http://www.gnu.org/licenses/>.                           *
#***************************************************************************************

#-------------------------------------------------
#
# Project created by QtCreator 2012-01-09T22:56:58
#
#-------------------------------------------------

QT       += core gui xml xmlpatterns webkit

TARGET = XBRLAIH
TEMPLATE = app

SOURCES += main.cpp \
        Sources/mainwindow.cpp \
    Sources/Aih.cpp \
    Sources/LeitorBackup.cpp \
    Sources/InstanciadorXbrl.cpp \
    Sources/Financiamento.cpp \
    Sources/Rubrica.cpp \
    Sources/Procedimento.cpp \
    Sources/LeitorRubrica.cpp \
    Sources/LeitorProcedimento.cpp \
    Sources/LeitorFinanciamento.cpp \
    Sources/LeitorCompetencia.cpp \
    Sources/GeradorEstatistica.cpp

HEADERS  += Headers/mainwindow.h \
    Headers/Aih.h \
    Headers/LeitorBackup.h \
    Headers/InstanciadorXbrl.h \
    Headers/Financiamento.h \
    Headers/Rubrica.h \
    Headers/Procedimento.h \
    Headers/LeitorRubrica.h \
    Headers/LeitorProcedimento.h \
    Headers/LeitorFinanciamento.h \
    Headers/LeitorCompetencia.h \
    Headers/GeradorEstatistica.h

FORMS    += mainwindow.ui

RESOURCES += \
    Resources.qrc
