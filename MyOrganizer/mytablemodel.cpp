#include "mytablemodel.h"

MyTableModel::MyTableModel(QObject *parent) : QAbstractListModel(parent)
{
    m_data.push_back(MyLine("Название задания","Описание задания","Дата начала","Дата окончания","Прогресс"));
}//MyTableModel(QObject *parent = nullptr);

#define SCI(n) static_cast<int>(n)
#define SCIDS SCI(m_data.size())

int MyTableModel::rowCount(const QModelIndex &parent) const
{
    return parent.isValid()? 0 : SCIDS;
}//int rowCount(const QModelIndex &parent) const override;

#define SCU(n) static_cast<unsigned>(n)
#define UIR SCU(index.row())

QVariant MyTableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid()) return QVariant();

    switch (role) {
    case IdRole: return QVariant(UIR);
    case NameRole: return QVariant(m_data[UIR].name);
    case DescRole: return QVariant(m_data[UIR].description);
    case StartRole: return QVariant(m_data[UIR].start);
    case EndRole: return QVariant(m_data[UIR].end);
    case ProgRole: return QVariant(m_data[UIR].progress);
    case IsDelRole: return QVariant(m_data[UIR].isDelete);
    default: return QVariant();
    }//switch (role)
}//QVariant data(const QModelIndex &index, int role) const override;

QHash<int, QByteArray> MyTableModel::roleNames() const
{
    QHash<int, QByteArray> roles = QAbstractListModel::roleNames();
    roles[IdRole]     = "taskID";
    roles[NameRole]   = "name";
    roles[DescRole]   = "description";
    roles[StartRole]  = "start";
    roles[EndRole]    = "end";
    roles[ProgRole]   = "progress";
    roles[IsDelRole]  = "isDelete";
    return roles;
}//QHash<int, QByteArray> roleNames() const override;

void MyTableModel::addLine(QString n, QString d, QString s, QString e, QString p)
{
    beginInsertRows(QModelIndex(), SCIDS, SCIDS);
    m_data.push_back(MyLine(n, d, s, e, p));
    endInsertRows();
    emit dataChanged(createIndex(0,0), createIndex(SCIDS, 0));
}//Q_INVOKABLE void addLine(QString n, QString d, QString s, QString e, QString p);

#define MyRemoveIfWithLambda std::remove_if(m_data.begin(), m_data.end(),[](auto& i){ return i.isDelete; } )

void MyTableModel::delLines()
{
    beginRemoveRows(QModelIndex(), 0, SCIDS);
    endRemoveRows();
    m_data.erase(MyRemoveIfWithLambda, m_data.end());
    beginInsertRows(QModelIndex(), 0, SCIDS - 1);
    endInsertRows();
    emit dataChanged(createIndex(0,0), createIndex(SCIDS, 0));
}//Q_INVOKABLE void delLines();

void MyTableModel::setIsDel(int index)
{
    m_data[SCU(index)].isDelete = !m_data[SCU(index)].isDelete;
}//Q_INVOKABLE void setIsDel(int index);

void MyTableModel::changeLineData(int index, QString n, QString d, QString s, QString e, QString p)
{
    m_data[SCU(index)] = MyLine(n, d, s, e, p);
    emit dataChanged(createIndex(0,0), createIndex(SCIDS, 0));
}//Q_INVOKABLE void changeLineData(int index);
