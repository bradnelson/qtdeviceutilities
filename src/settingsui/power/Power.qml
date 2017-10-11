/****************************************************************************
**
** Copyright (C) 2017 The Qt Company Ltd.
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
import QtQuick 2.0
import QtQuick.Controls 2.1
import QtDemoLauncher.QtButtonImageProvider 1.0

Item {
    id: root
    property int margin: root.width * 0.05

    Text {
        id: powerText
        anchors.top: parent.top
        anchors.left: parent.left
        fontSizeMode: Text.Fit
        minimumPixelSize: 1
        font.pixelSize: parent.height * 0.05
        color: "white"
        text: qsTr("Power")
        font.family: appFont
        font.styleName: "Bold"
    }
    Rectangle {
        id: btmLine
        anchors.top: powerText.bottom
        anchors.topMargin: parent.height * 0.025
        anchors.left: powerText.left
        width: parent.width * 0.275
        height: parent.height * 0.005
    }

    QtButton {
        id: shutdownButton
        width: btmLine.width
        height: parent.height * 0.075
        anchors.top: btmLine.bottom
        anchors.topMargin: parent.height * 0.05
        fillColor: "#41cd52"
        borderColor: "transparent"
        text: qsTr("SHUTDOWN")
        onClicked: {
            shutdownPopup.powerOffText = qsTr("Shut down the system?")
            shutdownPopup.buttonText = qsTr("SHUT DOWN")
            shutdownPopup.open()
        }
    }
    QtButton {
        id: rebootButton
        width: btmLine.width
        height: parent.height * 0.075
        anchors.top: shutdownButton.bottom
        anchors.topMargin: parent.height * 0.05
        fillColor: "#41cd52"
        borderColor: "transparent"
        text: qsTr("REBOOT")
        onClicked: {
            shutdownPopup.powerOffText = qsTr("Reboot the system?")
            shutdownPopup.buttonText = qsTr("REBOOT")
            shutdownPopup.open()
        }
    }
}
