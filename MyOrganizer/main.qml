import QtQuick 2.12
import QtQuick.Window 2.12

Window {
    id: root
    visible: true
    width: 840
    height: 480
    title: qsTr("My Organaizer")

    Table {
        id: _table
    }//Table

    AddButton {
        size: 75
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        onClicked: { _aTD.open() }
    }//AddButton

    AddTaskDialog {
        id: _aTD
        visible: false
        _id: _table.model.rowCount()
        onAccepted: {
            _table.model.addLine(task_name, task_description, start_date, end_date, progress)
            _id = _table.model.rowCount()
        }//onAccepted
    }//AddTaskDialog
}//root
