#-------------------------------------------------
#
# Project created by QtCreator 2017-03-14T15:40:00
#
#-------------------------------------------------

QT       += core gui
QT       += xml

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CiaicMemorias
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    AssociativeMemories.cpp \
    LearningAlgorithm.cpp \
    BinaryAssociativeMemories.cpp \
    LearnMatrix.cpp \
    DataFormat.cpp \
    Util.cpp \
    InputReader.cpp \
    InputFileReader.cpp \
    CsvFileReader.cpp \
    OutputWriter.cpp \
    OutputFileWriter.cpp \
    CsvFileWriter.cpp \
    AlfaBeta.cpp \
    AlfaBetaMax.cpp \
    AlfaBetaMin.cpp \
    AlfaBetaMaxComplete.cpp \
    form.cpp \
    XmlFileReader.cpp \
    ProjectEditor.cpp

HEADERS  += mainwindow.h \
    AssociativeMemories.h \
    LearningAlgorithm.h \
    BinaryAssociativeMemories.h \
    LearnMatrix.h \
    DataFormat.h \
    Util.h \
    InputReader.h \
    InputFileReader.h \
    CsvFileReader.h \
    OutputWriter.h \
    OutputFileWriter.h \
    CsvFileWriter.h \
    AlfaBeta.h \
    AlfaBetaMax.h \
    AlfaBetaMin.h \
    AlfaBetaMaxComplete.h \
    form.h \
    XmlFileReader.h \
    ProjectEditor.h

FORMS    += mainwindow.ui \
    form.ui \
    ProjectEditor.ui
