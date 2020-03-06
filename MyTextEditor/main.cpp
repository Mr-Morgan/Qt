﻿#include "mainwindow.h"
#include <QApplication>

/*

 * HomeWork for Lesson 3: "My Text Editor"

1.  Написать программу "Текстовый редактор", используя виджет QTextEdit, с возможностью отмены изменений.
    Информацию об изменениях хранить в контейнере (например, в QStack). Постарайтейсь не использовать встроенные
    возможности виджета, а именно методы redo(), undo().
    ] изменения означают слово.
    ] слово означает набор символов ограниченный пробелами.
    * отмена удаления восстанавливает последнее удаленное (частично удаленное) слово.

2.  Добаить в Текстовый редактор файл описания. Текстовый файл с описанием разместить в ресурсах программы. Для
    вызова описания разместить на форме соответствующую кнопку (о программе).

3.  Добавить в Текстовый редактор возможность открывать текстовые файлы (с расширением .txt).

4.  Добавить в Текстовый редактор возможность сохранить содержимое текстового поля. Если оно сохраняется в бинарный
    файл, сохранять имя автора, разместив поле QLineEdit, а если в тестовом виде - запись в этом поле игнорировать.

 * HomeWork for Lesson 4: "My Text Editor"

2.  Создать фильтр в текстовом редакторе, перехватывающий вызовы контекстного меню.
    Добавить режим «Открыть только для чтения», блокирующий любые правки.

 * HomeWork for Lesson 5: "My Text Editor"

1.  Добавить в текстовый редактор выбор из нескольких таблиц стилей.

 * HomeWork for Lesson 6: "My Text Editor"

1.  Добавить меню в текстовый редактор.

2.  Добавить в текстовый редактор печать, класс печати. Учтите, что строка может не
    помещаться по ширине страницы. Реализовать разбиение текста на дополнительные строки.

3.  Новая строка должна разделяться горизонтальной линией (тег <hr>). Добавить опцию
    нумерации абзацев. Добавить возможность вставки таблиц.

4.  * Добавить в текстовый редактор поддержку многодокументного интерфейса.

 * HomeWork for Lesson 7: "My Text Editor"

1.  В проект "Текстовый редактор" (можно взять из предыдущих ДЗ) добавить:

    a. возможность копировать формат фрагмента текста и применять к другому фрагменту.
    b. возможность выравнивания текста по правому и левому краю, а также по центру.
    c. возможность выбора шрифта

 * HomeWork for Lesson 8: "My Text Editor"

1.  Добавить в текстовый редактор возможность вставлять дату и время в текст по позиции
    курсора.
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}//int main(int argc, char *argv[])
