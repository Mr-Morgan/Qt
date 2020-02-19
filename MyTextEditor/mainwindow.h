#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
#include <QMessageBox>
#include <QTextStream>
#include <QFile>

#include "mytextedit.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_actionFullScreen_triggered();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionAbout_triggered();
    void on_open_triggered();
    void on_save_triggered();
    void on_open_read_only_triggered();

    void on_actionExit_triggered();

    void on_actionDayNight_triggered();

private:
    Ui::MainWindow *ui;
    bool NightMode = false;
};//class MainWindow
#endif // MAINWINDOW_H
