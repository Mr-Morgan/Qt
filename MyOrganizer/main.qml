import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    visible: true
    width: 800
    height: 480
    title: qsTr("My Organaizer")

    Table {

    }//Table

    AddButton {
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        onClicked: { _addTaskDialog.open() }
    }//AddButton

    AddTaskDialog {
        id: _addTaskDialog
        visible: false
    }//AddTaskDialog

}//root
