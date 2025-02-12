/*******************************************************************************
 *  Copyright 2012-2021 Esri
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 ******************************************************************************/

import QtQuick 2.12

Rectangle {
    id: handle

    property var palette
    property bool pressed
    property bool hovered
    property bool vertical
    property bool visualFocus
    property bool lingeringFocus

    implicitWidth: 18
    implicitHeight: 18
    radius: 50
    rotation: handle.vertical ? -90 : 0
    color: handle.pressed ? Calcite.brandHover : handle.lingeringFocus || mouseArea.containsMouse ? Calcite.brand : Calcite.foreground1
    border {
        width: 2
        color: handle.lingeringFocus || handle.hovered ? Calcite.brand : Calcite.borderInput
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
        hoverEnabled: true
        propagateComposedEvents: true
        onPressed: mouse.accepted = false
        onReleased: mouse.accepted = false
        onPositionChanged: mouse.accepted = false
    }
}
