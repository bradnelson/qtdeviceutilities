QT  += core dbus

INCLUDEPATH += $${PWD}
INCLUDEPATH += $${PWD}/bluez

HEADERS += \
    $$PWD/bluetoothdevice_p.h \
    $$PWD/datatypes.h \

SOURCES += \
    $$PWD/bluetoothdevice_p.cpp

qtHaveModule(networksettings) {
    DEFINES += USE_CONNMAN_BLUETOOTH
    INCLUDEPATH += $${PWD}/../../networksettings/connman
}
