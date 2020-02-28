#ifndef INSPECCHAR_H
#define INSPECCHAR_H

#include <QString>

/*
1.  Написать класс, который будет вставлять в текст спецсимволы (4–5). Пригодится для символов, для которых нет клавиши на клавиатуре,
    но они часто используются в тексте: © — знак охраны авторского права, ‰ — промилле, ®, € — евро, ₽ — рубль. Например, ввод рубля в
    программе #@RUB$, или руб. (автоматически заменить на знак).
    #@EUR$ (Евро евро ЕВРО)
    #@RUB$ (Руб  руб  РУБ)
*/

class InSpecChar
{
    QString str;
public:
    InSpecChar(QString);
    QChar parse();
};//class InSpecChar

#endif // INSPECCHAR_H
