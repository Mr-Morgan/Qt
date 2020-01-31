#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <set>
#include <algorithm>
#include "inspecchar.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

    QStandardItemModel *model_ex2;
    QStandardItemModel *model_ex3;

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void setBackgroundRow(const Qt::GlobalColor &color);

private slots:
    void on_plainTextEdit_textChanged();

    void on_addButton_clicked();

    void on_removeButton_clicked();

    void on_checkBox_clicked();

    void on_redButton_clicked();

    void on_tableView_clicked(const QModelIndex &index);

    void on_greenButton_clicked();

    void on_blueButton_clicked();

    void on_grayButton_clicked();

    void on_whiteButton_clicked();

private:
    Ui::MainWindow *ui;
    std::set<int> selected_row;
};//class MainWindow

#endif // MAINWINDOW_H
