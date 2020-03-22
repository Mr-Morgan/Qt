import QtQuick 2.0
import Table 1.0

ListView {
    id: rootView
    width: parent.width
    height: contentHeight

    property bool delMode: false

    model: MyTableModel {

    }//MyTableModel

    delegate: TableLine {
        _id_text: if (index != 0) index
        back_color: if (index != 0) "#FFFFFF"
        task_name: name
        task_description: description
        start_date: start
        end_date: end
        prog: progress
        line_height: if (index != 0) line_height + line_height
        onDataChanged: { rootView.model.changeLineData(index, task_name, task_description, start_date, end_date, prog) }
    }//TableLine
}//rootView
