#-------------------------------------------------
#
# Project created by QtCreator 2013-12-21T18:42:11
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += network
QT       += printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Assignment2
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    category.cpp \
    collectiondatatype.cpp \
    collectiontype.cpp \
    department.cpp \
    history.cpp \
    role.cpp \
    borrower.cpp \
    multimediacollection.cpp \
    copycollection.cpp \
    databasehandler.cpp \
    showallcollections.cpp \
    showcopies.cpp \
    borrowerform.cpp \
    addcollectionform.cpp \
    addcopyform.cpp \
    borrowcopyform.cpp \
    returncopyform.cpp \
    addborrowerform.cpp \
    copystatusform.cpp \
    changestatusform.cpp

HEADERS  += mainwindow.h \
    multimediacollection.h \
    copycollection.h \
    collectiontype.h \
    collectiondatatype.h \
    department.h \
    category.h \
    role.h \
    borrower.h \
    history.h \
    databasehandler.h \
    showallcollections.h \
    showcopies.h \
    borrowerform.h \
    addcollectionform.h \
    addcopyform.h \
    borrowcopyform.h \
    returncopyform.h \
    addborrowerform.h \
    copystatusform.h \
    changestatusform.h

FORMS    += mainwindow.ui \
    showallcollections.ui \
    showcopies.ui \
    borrowerform.ui \
    addcollectionform.ui \
    addcopyform.ui \
    borrowcopyform.ui \
    returncopyform.ui \
    addborrowerform.ui \
    copystatusform.ui \
    changestatusform.ui
