/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: http://www.qt.io/licensing/
**
** This file is part of the Qt Device Utilities module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL3$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see http://www.qt.io/terms-conditions. For further
** information use the contact form at http://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file. Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "qnetworksettingsinterface_p.h"
#include "qnetworksettingsinterface.h"
#include "connman_technology_interface.h"
#include "connmancommon.h"

QNetworkSettingsInterfacePrivate::QNetworkSettingsInterfacePrivate(QNetworkSettingsInterface* parent)
    : QObject(parent)
    ,q_ptr(parent)
{

}

void QNetworkSettingsInterfacePrivate::initialize(const QString& path, const QVariantMap& properties)
{
    m_technology = new NetConnmanTechnologyInterface("net.connman", path,
                                                  QDBusConnection::systemBus(), this);
    connect(m_technology, SIGNAL(PropertyChanged(QString,QDBusVariant)),
           this, SLOT(updateProperty(QString,QDBusVariant)));

    updateProperty(PropertyName, properties[PropertyName]);
    updateProperty(PropertyType, properties[PropertyType]);
    updateProperty(PropertyConnected, properties[PropertyConnected]);
    updateProperty(PropertyPowered, properties[PropertyPowered]);
}

void QNetworkSettingsInterfacePrivate::updateProperty(const QString &name, const QDBusVariant &value)
{
    updateProperty(name, value.variant());
}

void QNetworkSettingsInterfacePrivate::updateProperty(const QString &name, const QVariant &value)
{
    Q_Q(QNetworkSettingsInterface);
    if (name == PropertyName) {
        m_name = qdbus_cast<QString>(value);
    }
    else if (name == PropertyType) {
        qdbus_cast<QString>(value) >> m_type;
        emit q->typeChanged();
    }
    else if (name == PropertyConnected) {
        bool connected = qdbus_cast<bool>(value);
        if (connected)
            m_state.setState(QNetworkSettingsState::Online);
        else
            m_state.setState(QNetworkSettingsState::Disconnect);
        emit q->stateChanged();
    }
    else if (name == PropertyPowered) {
        m_powered = qdbus_cast<bool>(value);
        emit q->poweredChanged();
    }
}

void QNetworkSettingsInterfacePrivate::setState(QNetworkSettingsState::States aState)
{
    Q_Q(QNetworkSettingsInterface);
    m_state.setState(aState);
    emit q->stateChanged();
}

void QNetworkSettingsInterfacePrivate::setPowered(const bool aPowered)
{
    m_technology->SetProperty(PropertyPowered, QDBusVariant(QVariant(aPowered)));
}

void QNetworkSettingsInterfacePrivate::scan()
{
    m_technology->Scan();
}