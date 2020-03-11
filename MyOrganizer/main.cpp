#include <QGuiApplication>
#include <QQmlApplicationEngine>

/*
1.  Создать внешний вид программы-органайзера, которая будет отображать задачи.
    Каждая задача состоит из следующих пунктов:

        * id задачи (уникальный номер)
        * название задачи
        * описание задачи
        * дата начала выполнения задачи (в формате dd.mm.yyyy)
        * дата окончания выполнения задачи (в формате dd.mm.yyyy)
        * текущий прогресс (число от 0 до 100%)

    Для этого создать 4 qml файла:

        * Основное окно (main.qml)
        * Рабочая область
        * Делегат
        * Модель (заполнить начальными данными)

2.  Создать пользовательский виджет - кнопку в отдельном файле. Разместить в рабочей
    области кнопку "Добавить", которая будет добавлять новое задание.

3.  Создать окно для добавления нового задания. В этом окне должны быть поля для ввода
    составляющих, которые есть у любой задачи (см. 1 задание), кроме id (он будет
    генерироваться автоматически). Предусмотреть валидацию пользовательского ввода,
    например, текущий прогресс - это дожно быть целое число от 0 до 100.

4.  (По желанию) Ввод даты начала и окончания выполнения задачи осуществить через виджет календаря.
*/


int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}//int main(int argc, char *argv[])
