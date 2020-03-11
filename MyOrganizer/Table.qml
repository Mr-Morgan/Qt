import QtQuick 2.0

ListView {
    id: rootView
    width: parent.width
    height: parent.height
    anchors.fill: parent

    model: ModelLine {

    }//ModelLine

    delegate: TableLine {
          _id: index
          _id_text: if (_id != 0) _id
          back_color: if (_id != 0) "#FFFFFF"
          task_name: name
          task_description: description
          start_date: start
          end_date: end
          progress: prog
          line_height: if (_id != 0) _height
    }//TableLine
}//rootView
