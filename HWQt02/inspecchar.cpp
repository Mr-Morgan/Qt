#include "inspecchar.h"

InSpecChar::InSpecChar(QString text)
{
    str = text;
}//InSpecChar(QString)

QChar InSpecChar::parse()
{
    QChar result = 0xBF;
    if(str == "RUB" || str == "РУБ" || str == "Руб" || str == "руб") result = 0x20BD;
    else if(str == "EUR" || str == "ЕВРО" || str == "Евро" || str == "евро") result = 0x20AC;
    return result;
}//QString parse()
