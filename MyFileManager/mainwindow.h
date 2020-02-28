#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QLineEdit>
#include <QDir>
#include <QFileSystemModel>
#include <QKeyEvent>
#include <QString>
#include <QStack>
#include <QMessageBox>


#define STACK_MAX_SIZE 50

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void pushChanges(QStack<QString> &st, QString ch);
    ~MainWindow();

private slots:
    void on_actionFullScreen_triggered();
    void on_actionExit_triggered();
    void on_listView_doubleClicked(const QModelIndex &index);
    void on_path_returnPressed();
    void on_actionView_triggered();
    void on_actionBack_triggered();
    void on_actionForward_triggered();
    void on_actionAbout_triggered();

    void on_favour_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    QLineEdit *path;
    QFileSystemModel *model;
    QStack<QString> back;
    QStack<QString> forvard;
};//class MainWindow : public QMainWindow
#endif // MAINWINDOW_H
