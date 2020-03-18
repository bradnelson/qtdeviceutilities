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
#include "systemtime.h"
#include "systemtime_p.h"
#include <QTimer>

QT_BEGIN_NAMESPACE

/*!
    \module QtTimeDateSettings
    \qtvariable timedatesettings
    \ingroup qtdevice-utilities-cpp-modules
    \ingroup modules
    \title Qt Time and Date Settings C++ Classes
    \brief Provides functionality for controlling time and date settings.

    To use classes from this module, add this directive into the C++ files:

    \code
    #include <QtTimeDateSettings>
    \endcode

    To link against the corresponding C++ libraries, add the following to your
    qmake project file:

    \code
    QT += timedatesettings
    \endcode
*/

/*!
    \class SystemTime
    \inmodule QtTimeDateSettings
    \brief The SystemTime class manages the system date and time.
*/

/*!
    \property SystemTime::timeZone
    \brief Holds the current time zone string.
*/

/*!
    \property SystemTime::ntp

    Holds whether the system time is synchronized using NTP (Network
    Time Protocol).
*/

/*!
    \property SystemTime::time
    \brief Holds the current date and time.
*/

SystemTime::SystemTime(QObject *parent) :
    QObject(parent)
{
    QTimer *secTimer = new QTimer(this);
    connect(secTimer, &QTimer::timeout, this, &SystemTime::timeChanged);
    secTimer->setInterval(1001);
    secTimer->setSingleShot(false);
    secTimer->start();
}

bool SystemTime::ntp() const
{
    return false;
}

void SystemTime::setNtp(const bool aNtp)
{
    Q_UNUSED(aNtp)
}

void SystemTime::setTime(const QDateTime& aTime)
{
    Q_UNUSED(aTime)
}

QString SystemTime::timeZone() const
{
    return QString::fromUtf8("No Timezone Set");
}

void SystemTime::setTimeZone(const QString& aTimeZone)
{
    Q_UNUSED(aTimeZone)
}

QDateTime SystemTime::time() const
{
    return QDateTime::currentDateTime();
}

QT_END_NAMESPACE
