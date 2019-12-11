QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport multimedia serialport

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    abonnement_espace.cpp \
    abonnemnt_park.cpp \
    arduino.cpp \
    caisse.cpp \
    carte.cpp \
    client.cpp \
    commandes.cpp \
    connexion.cpp \
    departement.cpp \
    employee.cpp \
    four.cpp \
    jeu.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    place.cpp \
    qcustomplot.cpp \
    rayon.cpp \
    ticket.cpp \
    ticket_esp.cpp

HEADERS += \
    abonnement_espace.h \
    abonnemnt_park.h \
    arduino.h \
    caisse.h \
    carte.h \
    client.h \
    commandes.h \
    connexion.h \
    departement.h \
    employee.h \
    four.h \
    jeu.h \
    login.h \
    mainwindow.h \
    place.h \
    qcustomplot.h \
    rayon.h \
    ticket.h \
    ticket_esp.h

FORMS += \
    login.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
