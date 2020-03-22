#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QAbstractListModel>
#include <QObject>
#include <vector>

class MyTableModel : public QAbstractListModel
{
    Q_OBJECT
public:
    enum Roles { IdRole = Qt::UserRole + 1, NameRole, DescRole, StartRole, EndRole, ProgRole, IsDelRole };

    struct MyLine
    {
//        int32_t taskID;
        QString name;
        QString description;
        QString start;
        QString end;
        QString progress;
        bool isDelete;
        MyLine() {}
        MyLine(QString n, QString d, QString s, QString e, QString p, bool isD = false)
            : name(n), description(d), start(s), end(e), progress(p), isDelete(isD) {}
    };//struct MyLine

    MyTableModel(QObject *parent = nullptr);
    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addLine(QString n, QString d, QString s, QString e, QString p);
    Q_INVOKABLE void delLines();
    Q_INVOKABLE void setIsDel(int index);
    Q_INVOKABLE void changeLineData(int index, QString n, QString d, QString s, QString e, QString p);

private:
    std::vector<MyLine> m_data;
//    int32_t count;

};//class MyTableModel : public QAbstractListModel

#endif // MYTABLEMODEL_H
