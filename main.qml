import QtQuick 2.15
import QtQuick.Controls 2.15

ApplicationWindow {
    width: 640
    height: 480
    visible: true
    title: qsTr("Test")

    ScrollView {
        anchors.fill: parent

        ListView {
            id: listView
            width: parent.width
            model: SensorManager.sensors
            delegate: ItemDelegate {
                property var sensor: SensorManager.sensors[index]
                text: "[" + sensor.typeName() + "] " + sensor.name
                width: listView.width
                leftPadding: 50

                Rectangle {
                    anchors.left: parent.left
                    anchors.top: parent.top
                    anchors.leftMargin: 15
                    anchors.topMargin: (parent.height - height) / 2
                    width: 20
                    height: width
                    radius: width * 0.5
                    color: {
                        if(sensor.state == 0)
                            return "green";
                        if(sensor.state == 1)
                            return "orange";
                        else
                            return "red";
                    }
                }

                Text {
                    anchors.right: parent.right
                    anchors.top: parent.top
                    anchors.rightMargin: 15
                    anchors.topMargin: (parent.height - height) / 2
                    width: 20
                    height: width
                    text: sensor.strength + "%"
                    horizontalAlignment: Text.AlignRight
                    color: "white"
                }
            }
        }
    }
}
