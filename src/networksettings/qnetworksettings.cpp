/****************************************************************************
**
** Copyright (C) 2016 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the Device Utilities module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:GPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 3 or (at your option) any later version
** approved by the KDE Free Qt Foundation. The licenses are as published by
** the Free Software Foundation and appearing in the file LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/
#include "qnetworksettings.h"

QT_BEGIN_NAMESPACE

/*!
    \class QNetworkSettingsState
    \inmodule QtDeviceUtilities

    \brief The QNetworkSettingsState class represents the network interface
    state.

    \sa QNetworkSettingsManager
*/

/*!
    \enum QNetworkSettingsState::States

    This enum type holds the state of the network interface.

    \value  Idle
    \value  Failure
            Failed to connect.
    \value  Association
            Authentication in progress.
    \value  Configuration
            Configuration in progress.
    \value  Ready
            Connected to a network.
    \value  Disconnect
            Disconnected from a network.
    \value  Online
            Acquired an IP address.
    \value  Undefined
            Undefined state.
*/

/*!
    \property QNetworkSettingsState::state
    \brief The state of the network interface.

    \sa QNetworkSettingsState::States
*/

/*!
    \fn QNetworkSettingsState::stateChanged()
    This signal is emitted when the state of the network interface changes.

    \sa QNetworkSettingsState::States
*/

/*!
    Creates a new network interface state object with the state \a state and the
    parent \a parent.
*/
QNetworkSettingsState::QNetworkSettingsState(States state, QObject *parent)
    : QObject(parent)
    , m_state(state)
{
}

/*!
    Creates a new network interface state object with the parent \a parent.
*/
QNetworkSettingsState::QNetworkSettingsState(QObject *parent)
    : QObject(parent)
    , m_state(Undefined)
{
}

/*!
    Returns the network interface state.
*/
QNetworkSettingsState::States QNetworkSettingsState::state() const {
    return m_state;
}

/*!
    Sets the network interface state to \a state.
*/
void QNetworkSettingsState::setState(const States state) {
    m_state = state;
    emit stateChanged();
}

/*!
    \class QNetworkSettingsType
    \inmodule QtDeviceUtilities

    \brief The QNetworkSettingsType class represents the network interface
    type.

    \sa QNetworkSettingsManager
*/

/*!
    \enum QNetworkSettingsType::Types

    This enum type holds the type of the network interface.

    \value  Wired
            Wired network
    \value  Wifi
            Wifi network
    \value  Bluetooth
            Bluetooth network
    \value  Unknown
            Unknown network type
*/

/*!
    \property QNetworkSettingsType::type
    \brief The type of the network interface.

    \sa QNetworkSettingsType::Types
*/

/*!
    \fn QNetworkSettingsType::typeChanged()
    This signal is emitted when the type of the network interface changes.

    \sa QNetworkSettingsType::Types
*/

/*!
    Creates a new network interface type object with the type \a type and
    parent \a parent.
*/
QNetworkSettingsType::QNetworkSettingsType(Types type, QObject *parent)
    : QObject(parent)
    , m_type(type)
{
    m_type = type;
}

/*!
    Creates a new network interface type object with the parent \a parent.
*/
QNetworkSettingsType::QNetworkSettingsType(QObject *parent)
    : QObject(parent)
{
    m_type = Unknown;
}

/*!
    Returns the network interface type.
*/
QNetworkSettingsType::Types QNetworkSettingsType::type() const {
    return m_type;
}

/*!
    Sets the network interface type to \a type.
*/
void QNetworkSettingsType::setType(const Types type) {
    m_type = type;
    emit typeChanged();
}

/*!
    \class QNetworkSettingsIPv4
    \inmodule QtDeviceUtilities

    \brief The QNetworkSettingsIPv4 class encapsulates IPv4 network
    configuration.
*/

/*!
    \enum QNetworkSettingsIPv4::MethodType

    This enum type holds the method used for IPv4 configuration.

    \value  Dhcp
            The DHCP protocol is used for the network configuration.
    \value  Manual
            The network is configured manually.
    \value  Off
            The network is not configured.
*/

/*!
    \property QNetworkSettingsIPv4::address
    \brief Holds the IPv4 address.
*/

/*!
    \property QNetworkSettingsIPv4::gateway
    \brief Holds the IPv4 gateway address.
*/

/*!
    \property QNetworkSettingsIPv4::method
    \brief Holds the method of IPv4 configuration.

    \sa QNetworkSettingsIPv4::MethodType
*/

/*!
    \property QNetworkSettingsIPv4::mask
    \brief Holds the IPv4 network mask.
*/

/*!
    Creates a new IPv4 network configuration with the parent \a parent.
*/
QNetworkSettingsIPv4::QNetworkSettingsIPv4(QObject *parent)
    : QObject(parent)
{
}

QString QNetworkSettingsIPv4::address() const {
    return m_address;
}

void QNetworkSettingsIPv4::setAddress(const QString& address) {
    m_address = address;
    emit addressChanged();
}

QString QNetworkSettingsIPv4::gateway() const {
    return m_gateway;
}

void QNetworkSettingsIPv4::setGateway(const QString& gateway) {
    m_gateway = gateway;
    emit gatewayChanged();
}

QNetworkSettingsIPv4::MethodType QNetworkSettingsIPv4::method() const {
    return m_method;
}

void QNetworkSettingsIPv4::setMethod(const MethodType method) {
    m_method = method;
    emit methodChanged();
}

QString QNetworkSettingsIPv4::mask() const {
    return m_mask;
}

void QNetworkSettingsIPv4::setMask(const QString& mask) {
    m_mask = mask;
    emit maskChanged();
}

/*!
    \class QNetworkSettingsIPv6
    \inmodule QtDeviceUtilities

    \brief The QNetworkSettingsIPv6 class encapsulates IPv6 network
    configuration.
*/

/*!
    \enum QNetworkSettingsIPv6::MethodType

    This enum type holds the method used for IPv6 configuration.

    \value  Auto
            The network is configured automatically.
    \value  Manual
            The network is configured manually.
    \value  Off
            The network is not configured.
*/

/*!
    \enum QNetworkSettingsIPv6::PrivacyType
    \brief Holds the method of applying the privacy extensions in IPv6.

    \value  Disabled
            Disables privacy extensions in IPv6
    \value  Enabled
            Enables \l {https://tools.ietf.org/html/rfc4941}
            {Privacy Extensions for Stateless Address Autoconfiguration in IPv6}.
    \value  Preferred
            Enables privacy extensions and gives preference to the use of
            temporary addresses, even when a public address is available
*/

/*!
    \property QNetworkSettingsIPv6::address
    \brief Holds the IPv6 address.
*/

/*!
    \property QNetworkSettingsIPv6::gateway
    \brief Holds the IPv6 gateway address.
*/

/*!
    \property QNetworkSettingsIPv6::method
    \brief Holds the method of IPv6 configuration.

    \sa QNetworkSettingsIPv6::MethodType
*/

/*!
    \property QNetworkSettingsIPv6::privacy
    \brief Holds the method of applying privacy extensions for IPv6.

    \sa QNetworkSettingsIPv6::PrivacyType
*/

/*!
    \property QNetworkSettingsIPv6::prefixLength
    \brief Holds the IPv6 network prefix length in bits.
*/


/*!
    Creates a new IPv6 network configuration with the parent \a parent.
*/
QNetworkSettingsIPv6::QNetworkSettingsIPv6(QObject *parent)
    : QObject(parent)
{
}

QString QNetworkSettingsIPv6::address() const {
    return m_address;
}

void QNetworkSettingsIPv6::setAddress(const QString& address) {
    m_address = address;
    emit addressChanged();
}

QString QNetworkSettingsIPv6::gateway() const {
    return m_gateway;
}

void QNetworkSettingsIPv6::setGateway(const QString& gateway) {
    m_gateway = gateway;
    emit gatewayChanged();
}

QNetworkSettingsIPv6::MethodType QNetworkSettingsIPv6::method() const {
    return m_method;
}

void QNetworkSettingsIPv6::setMethod(const MethodType method) {
    m_method = method;
    emit methodChanged();
}

QNetworkSettingsIPv6::PrivacyType QNetworkSettingsIPv6::privacy() const {
    return m_privacy;
}

void QNetworkSettingsIPv6::setPrivacy(const PrivacyType privacy) {
    m_privacy = privacy;
    emit privacyChanged();
}

int QNetworkSettingsIPv6::prefixLength() const {
    return m_prefixLength;
}

void QNetworkSettingsIPv6::setPrefixLength(const int& prefixLength) {
    m_prefixLength = prefixLength;
    emit prefixLengthChanged();
}


/*!
    \class QNetworkSettingsProxy
    \inmodule QtDeviceUtilities
    \brief The QNetworkSettingsProxy class encapsulates network proxy
    configuration.
*/

/*!
    \enum QNetworkSettingsProxy::MethodType
    \brief Holds the network proxy configuration method.

    \value  Direct
            Direct network connection, no proxy in use
    \value  Auto
            Automatic proxy configuration
    \value  Manual
            Manual proxy configuration

    \sa url
*/

/*!
    \property QNetworkSettingsProxy::method
    \brief Holds the network proxy configuration method.

    \sa MethodType
*/

/*!
    \property QNetworkSettingsProxy::url
    \brief Holds the proxy URL.

    For manual proxy configuration, this property holds the proxy server
    address. For automatic configuration, it holds the proxy auto-config URL.

    \sa MethodType
*/

/*!
    \property QNetworkSettingsProxy::excludes
    \readonly
    \brief The model containing the proxy exclusion list.

    The addresses in the proxy exclusion list are accessed directly,
    instead of forwarding the requests to a proxy.

    This property can be used as a model for a view
    that lists the proxy exclusion addresses.

    \sa QNetworkSettingsAddressModel
*/

/*!
    Creates a new proxy configuration with the parent \a parent.
*/
QNetworkSettingsProxy::QNetworkSettingsProxy(QObject *parent)
    : QObject(parent)
{

}

QUrl QNetworkSettingsProxy::url() const {
    return m_url;
}

void QNetworkSettingsProxy::setUrl(const QUrl& url) {
    m_url = url;
    emit urlChanged();
}

QAbstractItemModel* QNetworkSettingsProxy::servers(void) {
    return &m_servers;
}

void QNetworkSettingsProxy::setServers(const QStringList& servers) {
    m_servers.setStringList(servers);
    emit serversChanged();
}

QStringList QNetworkSettingsProxy::servers() const {
    return m_servers.stringList();
}

QAbstractItemModel* QNetworkSettingsProxy::excludes(void) {
    return &m_excludes;
}

QStringList QNetworkSettingsProxy::excludes() const {
    return m_excludes.stringList();
}

void QNetworkSettingsProxy::setExcludes(const QStringList& excludes) {
    m_excludes.setStringList(excludes);
    emit excludesChanged();
}

QNetworkSettingsProxy::MethodType QNetworkSettingsProxy::method(void) const {
    return m_method;
}

void QNetworkSettingsProxy::setMethod(const MethodType& method) {
    m_method = method;
    emit methodChanged();
}

/*!
    \class QNetworkSettingsWireless
    \inmodule QtDeviceUtilities
    \brief The QNetworkSettingsWireless class encapsulates the configuration
    for a Wifi network service.
*/

/*!
    \enum QNetworkSettingsWireless::SecurityFlags
    \brief This enum type holds the wireless security protocol used to
    protect the connection.

    \value  None
            Not protected
    \value  WEP
            Wired Equivalent Privacy (WEP)
    \value  WPA
            Wi-Fi Protected Access (WPA)
    \value  WPA2
            Wi-Fi Protected Access, version 2 (WPA2)
*/

/*!
    \property QNetworkSettingsWireless::signalStrength
    \brief Holds the Wifi signal strength, in the range from 0 to 100.
*/

/*!
    \property QNetworkSettingsWireless::hidden
    \readonly
    \brief Holds whether the wireless SSID is hidden.
*/

/*!
    \property QNetworkSettingsWireless::isOutOfRange
    \brief Holds whether the Wifi access point is out of range.
*/


/*!
    Creates a new Wifi network configuration with the parent \a parent.
*/
QNetworkSettingsWireless::QNetworkSettingsWireless(QObject* parent)
  : QObject(parent) {
}

/*!
    Returns whether the Wifi network supports the wireless security
    protocols specified in \a security.

    \sa QNetworkSettingsWireless::SecurityFlags
*/
bool QNetworkSettingsWireless::supportsSecurity(SecurityFlags security) {
    if (m_securityFlags & security) {
        return true;
    }
    return false;
}

bool QNetworkSettingsWireless::hidden() const {
    return m_hidden;
}

void QNetworkSettingsWireless::setHidden(const bool hidden) {
    m_hidden = hidden;
    emit hiddenChanged();
}

int QNetworkSettingsWireless::signalStrength() const {
    return m_signalStrength;
}

void QNetworkSettingsWireless::setSignalStrength(const int signalStrength) {
    m_signalStrength = signalStrength;
    emit signalStrengthChanged();
}

void QNetworkSettingsWireless::setSecurity(const SecurityFlags security) {
    if (security == None) {
        m_securityFlags = None;
    } else {
        m_securityFlags |= security;
    }
}

void QNetworkSettingsWireless::setOutOfRange(const bool aOutOfRange) {
    m_isOutOfRange = aOutOfRange;
    emit outOfRangeChanged();
}

bool QNetworkSettingsWireless::outOfRange() const {
    return m_isOutOfRange;
}

QT_END_NAMESPACE
