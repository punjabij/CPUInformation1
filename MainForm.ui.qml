import QtQuick 2.4

Rectangle {
    property alias mouseArea: mouseArea

    width: 360
    height: 360

    ListView {
        id: listView1
        x: 0
        y: 0
        width: 360
        height: 360
        delegate: Item {
            x: 5
            width: 80
            height: 40
            Row {
                id: row1
                Rectangle {
                    width: 40
                    height: 40
                    color: colorCode
                }

                Text {
                    text: name
                    font.bold: true
                    anchors.verticalCenter: parent.verticalCenter
                }
                spacing: 10
            }
        }
        model: ListModel {
            ListElement {
                name: "Grey"
                colorCode: "grey"
            }

            ListElement {
                name: "Red"
                colorCode: "red"
            }

            ListElement {
                name: "Blue"
                colorCode: "blue"
            }

            ListElement {
                name: "Green"
                colorCode: "green"
            }
        }
    }

    MouseArea {
        id: mouseArea
        anchors.fill: parent
    }

    Text {
        anchors.centerIn: parent
        text: "Hello World"
    }

}

