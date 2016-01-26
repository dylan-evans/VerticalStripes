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
        width: 200
        height: 32
        radius: 6
        color: "white"
        border.color: "red"
        TextInput {
            anchors.centerIn: parent
            id: barcodeText
            width: 190
            text: "123"
            font.pixelSize: 30
            maximumLength: 12
        }

    }

    Button {
        anchors.left: barcodeArea.right
        height: 32
        text: "Print"
        onClicked: {
            if (barcodeText.text) {
                var label = "^XA^LH 80,80\n^BCN,100^FD" + barcodeText.text
                        + "^FS\n^LH0,0\n^XZ";
                print("Clicked: " + label);
                zebra.open("Labels");
                zebra.print(label);
                zebra.close();
            }
        }
    }

    RawPrinter {
        id: "zebra"
    }
}
