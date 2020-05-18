import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2

import Sort 1.0

Window {
    visible: true
    width: 640
    height: 480
    title: qsTr("Sorting visual")

    Column {
        spacing: 10
        anchors.fill: parent
        anchors.margins: 25
        VisualSort {
            id: visualSortId
            width: parent.width
            height: parent.height - parent.spacing - buttonId.height
        }
        Button {
            id: buttonId
            text: visualSortId.init ? "Sort" : "Init"
            width: parent.width
            onClicked: visualSortId.start()
            background: Rectangle {
                anchors.fill: parent
                color: "#00796b"
            }
            contentItem: Label {
                text: qsTr("<b>%1</b>").arg(buttonId.text)
                color: "white"
                anchors.fill: parent
                verticalAlignment: Text.AlignVCenter
                horizontalAlignment: Text.AlignHCenter
            }
        }
    }
}
