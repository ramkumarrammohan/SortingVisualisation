import QtQuick 2.9
import QtQuick.Window 2.2
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0

ApplicationWindow {
    visible: true
    width: 640
    height: 480
//    title: qsTr("")

    header: Rectangle {
        id: headerContainerId
        height: 40
        width: parent.width
        layer.enabled: true
        layer.effect: DropShadow {
            samples: 16
            color: "#000000"
            verticalOffset: -1
            anchors.fill: source
            source: headerContainerId
        }

        Label {
            height: parent.height
            width: parent.width * 0.6
            text: "<b>Sort visualizer</b>"
            anchors.centerIn: parent
            verticalAlignment: Text.AlignVCenter
            horizontalAlignment: Text.AlignHCenter
        }

        MouseArea {
            height: parent.height
            width: height
            anchors.right: parent.right
            Image {
                anchors.fill: parent
                anchors.margins: 10
                source: "qrc:/images/menu.png"
            }
            onClicked: sidePaneId.visible = !sidePaneId.visible
        }
    }

    SidePane {
        id: sidePaneId
    }

    MainView {
        id: mainviewId
        height: parent.height
        width: parent.width - sidePaneId.width
    }
}
