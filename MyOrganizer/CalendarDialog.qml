import QtQuick 2.5
import QtQuick.Controls 2.12
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Dialogs 1.2

Dialog {
    id: _dialogCalendar
    width: 350
    height: 400
    property string date: ""

    standardButtons: StandardButton.Cancel | StandardButton.Ok

    Calendar {
        id: _calendar
        anchors.fill: parent
    }//_calendar

    onAccepted: {
        date = Qt.formatDate(_calendar.selectedDate, "dd.MM.yyyy");
    }//onAccepted
}//dialogCalendar

