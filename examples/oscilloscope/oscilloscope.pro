# -*- mode: sh -*- ################################################
# Qwt Widget Library
# Copyright (C) 1997   Josef Wilgen
# Copyright (C) 2002   Uwe Rathmann
#
# This library is free software; you can redistribute it and/or
# modify it under the terms of the Qwt License, Version 1.0
###################################################################

include( ../examples.pri )

TARGET   = oscilloscope

HEADERS = \
    clock.h \
    signaldata.h \
    plot.h \
    knob.h \
    wheelbox.h \
    signalgenerator.h \
    curvedata.h \
    mainwindow.h 

SOURCES = \
    clock.cpp \
    signaldata.cpp \
    plot.cpp \
    knob.cpp \
    wheelbox.cpp \
    signalgenerator.cpp \
    curvedata.cpp \
    mainwindow.cpp \
    main.cpp