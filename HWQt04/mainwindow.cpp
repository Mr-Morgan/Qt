#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}//MainWindow(QWidget *parent = nullptr)

MainWindow::~MainWindow()
{
    delete ui;
}//~MainWindow()

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Return || event->key() == Qt::Key_Enter)
        setWindowTitle(ui->lineEdit->text());
}//void keyReleaseEvent(QKeyEvent *event)
