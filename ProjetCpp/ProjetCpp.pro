QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11 cosole network

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
LIBS += -L"C:/Program Files/OpenSSL-Win64/lib" -llibcrypto -llibssl
SOURCES += \
    connexion.cpp \
    demande.cpp \
    dialogoublie.cpp \
    equipement.cpp \
    fournisseur.cpp \
    infofour.cpp \
    loginscreen.cpp \
    main.cpp \
    mainwindow.cpp \
    operation.cpp \
    panier.cpp \
    profile.cpp \
    smtp.cpp \
    user.cpp


HEADERS += \
    connexion.h \
    demande.h \
    dialogoublie.h \
    equipement.h \
    fournisseur.h \
    infofour.h \
    loginscreen.h \
    mainwindow.h \
    operation.h \
    panier.h \
    profile.h \
    smtp.h \
    user.h

FORMS += \
    demande.ui \
    dialogoublie.ui \
    loginscreen.ui \
    mainwindow.ui \
    profile.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Images.qrc
