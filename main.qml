import QtQuick 2.5
import QtQuick.Window 2.2
import QtQuick.Controls 1.4
import RawPrinter 1.0

Window {
    visible: true
    color: "lightblue"
    width: 300
    height: 200

    Rectangle {
        id: barcodeArea
        x: 10
        y: 10
        width: 200
        height: 32
        radius: 3
        color: "white"
        border.color: "gray"
        TextInput {
            anchors.centerIn: parent
            id: barcodeText
            width: 190
            text: ""
            font.pixelSize: 30
            maximumLength: 12
        }
    }

    Button {
        //anchors.left: barcodeArea.right
        y: 10
        x: 220
        height: 32
        text: "Print"
        onClicked: {
            if (barcodeText.text) {
                var label = "^XA^LH 80,80\n^BCN,100^FD" + barcodeText.text
                        + "^FS\n^LH0,0\n^XZ";
                print("Clicked: " + label);
                zebra.open(deviceText.text);
                zebra.print(label);
                zebra.close();
            }
        }
    }

    Rectangle {
        id: deviceArea
        x: 10
        y: 50
        width: 100
        height: 16
        radius: 3
        color: "white"
        border.color: "gray"
        TextInput {
            anchors.centerIn: parent
            id: deviceText
            width: 90
            text: "Labels"
            font.pixelSize: 12
        }
    }



    RawPrinter {
        id: "zebra"
    }

    Component.onCompleted: {
        barcodeText.forceActiveFocus();
    }
}
