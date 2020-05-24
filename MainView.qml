import QtQuick 2.9
import QtQuick.Controls 2.2
import Sort 1.0

Column {
    spacing: 10

    property alias visualSort: visualSortId

    VisualSort {
        id: visualSortId
        width: parent.width
        height: parent.height - parent.spacing - buttonId.height
    }

    Button {
        id: buttonId
        text: visualSortId.init ? "Sort" : "Init"
        width: parent.width
        onClicked: visualSortId.changeState()
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
