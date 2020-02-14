#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStack>
#include <QString>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QTextStream>
#include <QKeyEvent>

#define STACK_MAX_SIZE 50

enum BDKey {Backspace = 1, Delete};

struct Changes
{
    int32_t pos; //position
    QString data;
    bool del;    //is delete?
    Changes() {}
    Changes(int32_t p, QString d, bool de = false) : pos(p), data(d), del(de) {}
};//struct Changes

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void pushChanges(QStack<Changes> &st, Changes ch);
    ~MainWindow();

protected:
    virtual void keyReleaseEvent(QKeyEvent *event);

private slots:
    void on_actionFullScreen_triggered();
    void on_textEdit_textChanged();
    void on_actionUndo_triggered();
    void on_actionRedo_triggered();
    void on_actionAbout_triggered();
    void on_open_triggered();
    void on_save_triggered();

private:
    Ui::MainWindow *ui;
    QString twc;    //text without changes
    QStack<Changes> undo;
    QStack<Changes> redo;
    bool undoRedoFlag = false;
    BDKey key;
};//class MainWindow
#endif // MAINWINDOW_H
