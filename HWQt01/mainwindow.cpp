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

/*********************** Ex. 1 ****************************/
int calcSquarEq(double a, double b, double c, double &x1, double &x2)
{//возвращает количество действительных корней
    if (a == 0.0) {
        if (b == 0.0) return 0;
        else {
            x1 = -c / b;
            x2 = x1;
            return 1;
        }//if (b == 0.0)
    } else {
        double D = b*b - 4*a*c;
        if (D > 0.0) {
            x1 = (-b + sqrt(D))/(a+a);
            x2 = (-b - sqrt(D))/(a+a);
            return 2;
        } else if (D == 0.0) {
            x1 = -b /(a+a);
            x2 = x1;
            return 1;
        } else {
            x1 = -b /(a+a);         //Re
            x2 = sqrt(-D)/(a+a);    //Im
            return 0;
        }//if (D > 0.0)
    }//if (a == 0.0)
}//int calcSquarEq(double a, double b, double c, double &x1, double &x2)

void MainWindow::on_Ex1Calc_clicked()
{
    double x1 = 0.0, x2 = 0.0;
    switch (calcSquarEq(ui->aEdit->text().toDouble(), ui->bEdit->text().toDouble(), ui->cEdit->text().toDouble(), x1, x2)) {
    case 1: case 2:
        ui->ReImLabel->setText("Решение в поле действительных чисел:");
        ui->x1Label->setText(QString::number(x1,'f',3));
        ui->x2Label->setText(QString::number(x2,'f',3));
        break;
    case 0:
        ui->ReImLabel->setText("Решение в поле комплексных чисел:");
        ui->x1Label->setText(QString::number(x1,'f',3) + " + " + QString::number(x2,'f',3) + 'i');
        ui->x2Label->setText(QString::number(x1,'f',3) + " - " + QString::number(x2,'f',3) + 'i');
        break;
    }//switch (calcSquarEq(...))
}//void MainWindow::on_Ex1Calc_clicked()

/*********************** Ex. 2 ****************************/
double twoSidesAndAngle (double a, double b, double C)
{// Angle C in rad
    return sqrt(a*a + b*b - 2*a*b*cos(C));
}//double twoSidesAndAngle (double a, double b, double C)

const double pi = 2*acos(0.0);

void MainWindow::on_Ex2Calc_clicked()
{
    double c = 0;
    if (ui->radButton->isChecked()){
        c = twoSidesAndAngle(ui->aEdit_2->text().toDouble(), ui->bEdit_2->text().toDouble(), ui->CEdit_2->text().toDouble());
    } else if (ui->gradButton->isChecked()) {
        c = twoSidesAndAngle(ui->aEdit_2->text().toDouble(), ui->bEdit_2->text().toDouble(), ui->CEdit_2->text().toDouble()*pi/180);
    }//if (ui->radButton->isChecked())
    ui->cLabel->setText(QString::number(c,'f',3));
}//void MainWindow::on_Ex2Calc_clicked()

/*********************** Ex. 3 ****************************/
void MainWindow::on_replaceButton_clicked()
{
    ui->tEdit->setHtml(ui->ptEdit->toPlainText());
}//void MainWindow::on_replaceButton_clicked()

void MainWindow::on_addButton_clicked()
{
    QString old_str = ui->tEdit->toHtml();
    ui->tEdit->setHtml(old_str + ui->ptEdit->toPlainText());
}//void MainWindow::on_addButton_clicked()

/*********************** Ex. 4 ****************************/
void MainWindow::on_getDoc_clicked()
{
    QTextDocument *text_doc = ui->tEdit_2->document();
    ui->tEdit_2->setHtml(text_doc->metaInformation(QTextDocument::DocumentTitle));
}//void MainWindow::on_getDoc_clicked()
