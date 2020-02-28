#include "mainwindow.h"
#include <QApplication>

/*

 * HomeWork for Lesson 5: "My Text Editor"

2.  Написать просмотрщик файловой системы. При выборе каталога выводить список файлов и
    каталогов внутри выбранного.
    Добавить строку навигации, в которой можно указать текущий каталог.
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}//int main(int argc, char *argv[])
