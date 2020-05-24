import QtQuick 2.9
import QtQuick.Controls 2.2
import QtGraphicalEffects 1.0

Rectangle {
    id: rootId

    signal sortSelectionChanged(var index)

    width: 0
    height: parent.height
    anchors.right: parent.right
    visible: false
    layer.enabled: true
    layer.effect: DropShadow {
        samples: 16
        color: "#000000"
        horizontalOffset: 1
        anchors.fill: source
        source: rootId
    }

    Column {
        anchors.fill: parent
        anchors.margins: 10
        ComboBox {
            width: parent.width - 10
            model: ["Select", "Bubble sort", "Selection sort"]
            onCurrentIndexChanged: {
                mainviewId.visualSort.currentSort = currentIndex
            }
        }
    }

    onVisibleChanged: {
        if(visible)
            width = parent.width * 0.3
        else
            width = 0
    }
}
