#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->toolBar->addAction(ui->actionFullScreen);
    ui->toolBar->addAction(ui->actionUndo);
    ui->toolBar->addAction(ui->actionRedo);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionDayNight);
    ui->toolBar->addAction(ui->actionSettings);
    ui->toolBar->addAction(ui->actionAbout);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionExit);
}//MainWindow(QWidget *parent = nullptr)

MainWindow::~MainWindow()
{
    delete ui;
}//~MainWindow()

void MainWindow::on_actionFullScreen_triggered()
{
    if (isFullScreen()) {
        showNormal();
        ui->actionFullScreen->setIcon(QIcon(":/icons/icons/fullScreen.png"));
    } else {
        showFullScreen();
        ui->actionFullScreen->setIcon(QIcon(":/icons/icons/fullScreenOff.png"));
    }//if (isFullScreen())
//    (this->isFullScreen())?this->showNormal():this->showFullScreen();
}//on_actionFullScreen_triggered()

void MainWindow::on_actionUndo_triggered()
{
    ui->textEdit->on_actionUndo_triggered();
}//on_actionUndo_triggered()

void MainWindow::on_actionRedo_triggered()
{
    ui->textEdit->on_actionRedo_triggered();
}//on_actionRedo_triggered()

void MainWindow::on_actionAbout_triggered()
{
    QFile file(":/about.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        ui->textEdit->setReadOnly(false);
        ui->lineEdit->setReadOnly(false);
        ui->textEdit->setPlainText(QString(file.readAll()));
        ui->textEdit->moveCursor(QTextCursor::Start);
        ui->lineEdit->setText("Mr. Morgan");
        file.close();
    }//if (file.open(QIODevice::ReadOnly | QIODevice::Text))
}//on_actionAbout_triggered()

void MainWindow::on_open_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Выберите файл для открытия", QDir::current().path(),
                                                    QString("Текстовый файл(*.txt);;Бинарный файл(*.binary);;Все файлы(*.*)"));
    if (filename.length()) {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            ui->textEdit->setReadOnly(false);
            ui->lineEdit->setReadOnly(false);
            if (filename.right(7) == ".binary") ui->lineEdit->setText(stream.readLine());
            ui->textEdit->setPlainText(QString(stream.readAll()));
            ui->textEdit->moveCursor(QTextCursor::Start);
            file.close();
        }//if (file.open(..))
    } else QMessageBox::information(this, "Ошибка чтения файла", "Не удалось считать выбранный файл.");
}//on_open_triggered()

void MainWindow::on_save_triggered()
{
    QString filename = QFileDialog::getSaveFileName(this, "Выберите файл для сохранения", QDir::current().path(),
                                                    QString("Текстовый файл(*.txt);;Бинарный файл(*.binary)"));
    if (filename.length()) {
        QFile file(filename);
        if (file.open(QIODevice::WriteOnly | QIODevice::NewOnly)){
            QTextStream stream(&file);
            if (filename.right(7) == ".binary") stream << ui->lineEdit->text() << '\n';
            stream << ui->textEdit->toPlainText();
            file.close();
        }//if (file.open(..))
    }else QMessageBox::information(this, "Ошибка записи файла", "Не удалось записать данные в выбранный файл.");
}//on_save_triggered()

void MainWindow::on_open_read_only_triggered()
{
    emit ui->open->triggered();
    ui->textEdit->setReadOnly(true);
    ui->lineEdit->setReadOnly(true);
}//on_open_read_only_triggered()

void MainWindow::on_actionExit_triggered()
{
    close();
}//on_actionExit_triggered()

void MainWindow::on_actionDayNight_triggered()
{
    if (NightMode) {
        ui->actionDayNight->setIcon(QIcon(":/icons/icons/classic.png"));
        qApp->setStyleSheet("");
        ui->label->setText("<FONT COLOR=#000000>Author:</FONT>");
        NightMode = false;
    } else {
        QFile file(":/night.css");
        if (file.open(QIODevice::ReadOnly)) {
            ui->actionDayNight->setIcon(QIcon(":/icons/icons/night.png"));
            QString style = file.readAll();
            qApp->setStyleSheet(style);
            ui->label->setText("<FONT COLOR=#A6B4B5>Author:</FONT>");
            file.close();
            NightMode = true;
        }//if (file.open(QIODevice::ReadOnly))
    }//if (NightMode)
}//on_actionDayNight_triggered()
