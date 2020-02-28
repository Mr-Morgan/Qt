#include "mainwindow.h"

#include <QApplication>

/*
1.  Написать программу, которая будет находить корень квадратного уравнения второй степени,
    входные данные: ​a, b, c. Если нахождение корня невозможно, выводить сообщение в поле
    результата (или выводить результат в виде комплексного числа). Учитывать, что число ​ a
    может быть равно нулю.

2.  Расчет стороны треугольника по двум сторонам и углом между ними. Дополнительно:
    добавить переключатель из ​ QRadioButton для выбора единиц, в каких указан угол: градусах
    или радианах. Формулу для расчета можно найти по ссылке: https://www-formula.ru/2011-10-09-11-08-41.

3.  *Создать программу, разместить на поле виджет ​ QPlainTextEdit​ . Добавить кнопки: для
    добавления фиксированной строки, замены на готовый текст. Разместить ​ QTextEdit​ . Через
    метод ​ setHtml(QString) установите текст произвольного html-кода, например ​ <font
    color='red'>Hello</font>​ .

4.  Получите ​ QTextDocument ​ из виджета ​ QTextEdit (метод ​ document​ ). С помощью списка
    методов и переменных выберите, какие наиболее интересны для редактирования текста.
    Ознакомьтесь с работой подсказчика кода Qt Creator (​ Ctrl+Space​ ).
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}//int main(int argc, char *argv[])
