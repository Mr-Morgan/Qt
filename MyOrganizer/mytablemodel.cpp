#include "mytablemodel.h"

MyTableModel::MyTableModel(QObject *parent) : QAbstractListModel(parent)
{
    m_data.push_back(MyLine("Название задания","Описание задания","Дата начала","Дата окончания","Прогресс"));
}//MyTableModel(QObject *parent = nullptr);

#define SCIDS static_cast<int>(m_data.size())

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
    return roles;
}//QHash<int, QByteArray> roleNames() const override;

void MyTableModel::addLine(QString n, QString d, QString s, QString e, QString p)
{
    beginInsertRows(QModelIndex(), SCIDS, SCIDS);
    m_data.push_back(MyLine(n, d, s, e, p));
    endInsertRows();
    emit dataChanged(createIndex(0,0), createIndex(SCIDS, 0));
}//Q_INVOKABLE void addLine(QString n, QString d, QString s, QString e, QString p);
