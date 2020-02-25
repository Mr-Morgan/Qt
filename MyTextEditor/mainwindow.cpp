#include "mainwindow.h"
#include "ui_mainwindow.h"

#define ACTIVESUBWIN static_cast<MySubWindow*>(ui->mdiArea->activeSubWindow()->widget())

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->toolBar->addAction(ui->actionNewWindow);
    ui->toolBar->addAction(ui->actionUndo);
    ui->toolBar->addAction(ui->actionRedo);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionaddTable);
    ui->toolBar->addAction(ui->actionDayNight);
    ui->toolBar->addAction(ui->actionSettings);
    ui->toolBar->addAction(ui->actionFullScreen);
    ui->toolBar->addAction(ui->actionAbout);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionExit);

    on_actionNewWindow_triggered();
}//MainWindow(QWidget *parent = nullptr)

MainWindow::~MainWindow()
{
    delete ui;
}//~MainWindow()

void MainWindow::setLabelsText(QString text)
{
    for (auto i : ui->mdiArea->subWindowList())
        static_cast<MySubWindow*>(i->widget())->setLabelText(text);
}//void setLabelsText(QString text)

void MainWindow::on_actionFullScreen_triggered()
{
    if (isFullScreen()) {
        showNormal();
        ui->actionFullScreen->setIcon(QIcon(":/icons/icons/fullScreen.png"));
    } else {
        showFullScreen();
        ui->actionFullScreen->setIcon(QIcon(":/icons/icons/fullScreenOff.png"));
    }//if (isFullScreen())
}//on_actionFullScreen_triggered()

void MainWindow::on_actionUndo_triggered()
{
    ACTIVESUBWIN->undo();
}//on_actionUndo_triggered()

void MainWindow::on_actionRedo_triggered()
{
    ACTIVESUBWIN->redo();
}//on_actionRedo_triggered()

void MainWindow::on_actionAbout_triggered()
{
    QFile file(":/about.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QTextStream stream(&file);
        ACTIVESUBWIN->printText(stream, true);
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
            bool is_binary = (filename.right(7) == ".binary");
            ACTIVESUBWIN->printText(stream, is_binary, false);
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
        if (file.open(QIODevice::WriteOnly)){
            QTextStream stream(&file);
            bool is_binary = (filename.right(7) == ".binary");
            ACTIVESUBWIN->scanText(stream, is_binary);
            file.close();
        }//if (file.open(..))
    }else QMessageBox::information(this, "Ошибка записи файла", "Не удалось записать данные в выбранный файл.");
}//on_save_triggered()

void MainWindow::on_open_read_only_triggered()
{
    QString filename = QFileDialog::getOpenFileName(this, "Выберите файл для открытия", QDir::current().path(),
                                                    QString("Текстовый файл(*.txt);;Бинарный файл(*.binary);;Все файлы(*.*)"));
    if (filename.length()) {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
            QTextStream stream(&file);
            bool is_binary = (filename.right(7) == ".binary");
            ACTIVESUBWIN->printText(stream, is_binary, true);
            file.close();
        }//if (file.open(..))
    } else QMessageBox::information(this, "Ошибка чтения файла", "Не удалось считать выбранный файл.");
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
        ui->mdiArea->setBackground(QBrush(QColor("#9C9C9C")));
        setLabelsText("<FONT COLOR=#000000>Author:</FONT>");
        NightMode = false;
    } else {
        QFile file(":/night.css");
        if (file.open(QIODevice::ReadOnly)) {
            ui->actionDayNight->setIcon(QIcon(":/icons/icons/night.png"));
            QString style = file.readAll();
            qApp->setStyleSheet(style);
            ui->mdiArea->setBackground(QBrush(QColor("#374463")));
            setLabelsText("<FONT COLOR=#A6B4B5>Author:</FONT>");
            file.close();
            NightMode = true;
        }//if (file.open(QIODevice::ReadOnly))
    }//if (NightMode)
}//on_actionDayNight_triggered()

void MainWindow::on_actionPrint_triggered()
{
    QPrinter p;
    QPrintDialog pdlg(&p,this);
    pdlg.setWindowTitle("Печать");
    if (pdlg.exec() != QDialog::Accepted) return;
    ACTIVESUBWIN->print(&p);
}//on_actionPrint_triggered()

void MainWindow::on_actionNewWindow_triggered()
{
    MySubWindow *subwindow = new MySubWindow(ui->mdiArea);
    subwindow->setObjectName(QString::fromUtf8("subwindow"));

    NightMode? subwindow->setLabelText("<FONT COLOR=#A6B4B5>Author:</FONT>"):
               subwindow->setLabelText("<FONT COLOR=#000000>Author:</FONT>");

    ui->mdiArea->addSubWindow(subwindow);
    subwindow->show();
}//on_actionNewWindow_triggered()

void MainWindow::on_actionaddTable_triggered()
{
    MyTableDialog *dialog = new MyTableDialog (this);
    if (dialog->exec() == QDialog::Accepted) {
        DataNM data = dialog->getData();
        ACTIVESUBWIN->insertTable(data.n, data.m);
    }//if (dialog->exec() == QDialog::Accepted)
    delete dialog;
}//on_actionaddTable_triggered()
