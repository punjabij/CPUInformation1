import QtQuick 2.4
import QtQuick.Window 2.2

import CPUDetails 1.0

Item {
    id: mainWindow

    width: 800
    height: 600

    // TODO: theming
    readonly property int spacing: 5
    readonly property color backgroundColor: "grey"
    readonly property color borderColor: "#5D4C46"
    readonly property color buttonColor: "#F1A94E"
    readonly property color panelColor: "#F2EDD8"
    readonly property color listNormalColor: "#7B8D8E"
    readonly property color listHighlightColor: "#44B3C2"

    Rectangle {
        id: background
        anchors.fill: parent
        color: backgroundColor
    }

    ListView {
        id: list
        anchors.top: parent.top
        anchors.bottom: refreshButon.top
        anchors.left: parent.left
        anchors.right: fullInfoPanel.left
        anchors.margins: mainWindow.spacing

        spacing: mainWindow.spacing
        model: CPUList

        // Delegate displays basic CPU info: name, freqency, cache size
        delegate: Rectangle {
            height: 80
            width: list.width
            color: list.currentIndex == index ? mainWindow.listHighlightColor : mainWindow.listNormalColor
            border.color: mainWindow.borderColor

            Text {
                anchors.fill: parent
                anchors.margins: mainWindow.spacing

                elide: Text.ElideRight
                font.bold: true
                font.pixelSize: 20

                text: CPUList.count
            }
    }
  }

//Window {
//    visible: true

//    MainForm {
//        anchors.fill: parent
//        mouseArea.onClicked: {
//            Qt.quit();
//        }
//    }
//}

//ListView {
//    width: 100; height: 100

//    model: procModel
//    delegate: Rectangle {
//        height: 25
//        width: 100
//        color: "black"
//        Text { text: "processorId" }
//        Text { text: "cpuFrequencyMHz"
//                font.pixelSize: 12}

////        color: model.color()
////        Text { text: model.name() }
//    }
//}



//Rectangle {
//    id: page
//    width: 600; height: 200
//    color: "black"

////   Component {
////       id: itemDelegate


//    Item{
//           id: singleItem
//           width: 600
//           height: 200
////           property var thing: CPUInfo.modelData
//           Rectangle {
//               anchors.fill: parent
//               color: "red"
//               Text {
//                   text: CPUList // or any other field
//               }
//           }
////       }
//   }


////    ListView {
//////       anchors.fill: parent
////       id: listView
////       anchors.rightMargin: 0
////       anchors.bottomMargin: 0
////       anchors.leftMargin: 0
////       anchors.topMargin: 0
////       anchors.fill: parent
////       model: CPUList.processorList
////       delegate: itemDelegate
////       clip: true
////       spacing: 10
////    }


//}



