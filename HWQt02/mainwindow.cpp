#include "mainwindow.h"
#include "ui_mainwindow.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

/*********************** Ex. 2 ****************************/

    model_ex2 = new QStandardItemModel(this);
    ui->listView->setModel(model_ex2);
    model_ex2->appendRow(new QStandardItem(QIcon(":/c++.png"),        "C++"));
    model_ex2->appendRow(new QStandardItem(QIcon(":/c.png"),          "С"));
    model_ex2->appendRow(new QStandardItem(QIcon(":/c-sharp.png"),    "C#"));
    model_ex2->appendRow(new QStandardItem(QIcon(":/python.png"),     "Python"));
    model_ex2->appendRow(new QStandardItem(QIcon(":/java.png"),       "Java"));
    model_ex2->appendRow(new QStandardItem(QIcon(":/javascript.png"), "JavaScript"));
    model_ex2->appendRow(new QStandardItem(QIcon(":/php.png"),        "PHP"));

/*********************** Ex. 3 ****************************/

    model_ex3 = new QStandardItemModel(this);
    ui->tableView->setModel(model_ex3);
    QList<QStandardItem*> row;
    row.append(new QStandardItem("№"));
    row.append(new QStandardItem("Имя компьютера"));
    row.append(new QStandardItem("IP адрес"));
    row.append(new QStandardItem("MAC адрес"));
    model_ex3->appendRow(row);
    row.clear();
    row.append(new QStandardItem("1"));
    row.append(new QStandardItem("Компьютер 1"));
    row.append(new QStandardItem("192.168.0.3"));
    row.append(new QStandardItem("00:26:57:00:1f:02"));
    model_ex3->appendRow(row);
    row.clear();
    row.append(new QStandardItem("2"));
    row.append(new QStandardItem("Компьютер 2"));
    row.append(new QStandardItem("192.168.5.254"));
    row.append(new QStandardItem("01:0C:CD:01:00:00"));
    model_ex3->appendRow(row);
    row.clear();
    row.append(new QStandardItem("3"));
    row.append(new QStandardItem("Компьютер 3"));
    row.append(new QStandardItem("192.168.5.0"));
    row.append(new QStandardItem("01:0C:CD:01:01:FF"));
    model_ex3->appendRow(row);
}//MainWindow(QWidget *parent = nullptr)

MainWindow::~MainWindow()
{
    delete model_ex2;
    delete ui;
}//~MainWindow()

/*********************** Ex. 1 ****************************/

void MainWindow::on_plainTextEdit_textChanged()
{
    QString txt = ui->plainTextEdit->toPlainText();

    int pos = 0;
    while(1){ //нет защиты от дурака
        int fnd = txt.indexOf("#@", pos); //Пример1: #@RUB$
        if (fnd == -1) return;
        pos = fnd + 1;
        int r = txt.indexOf("$", fnd);
        int space = txt.indexOf(" ", fnd);
        if ((r<space || space==-1) && r!=-1){
            InSpecChar parseText(txt.mid(fnd+2,r-fnd-2)); //RUB
            QString answer = parseText.parse();
            txt.insert(r+1, answer);//Пример1: #@RUB$₽
            txt.remove(fnd, r-fnd+1); //Пример1: ₽
            ui->plainTextEdit->setPlainText(txt);
        }//if ((r<space || space==-1) && r!=-1)
    }//while(1)
}//on_plainTextEdit_textChanged()

/*********************** Ex. 2 ****************************/

void MainWindow::on_addButton_clicked()
{
    model_ex2->appendRow(new QStandardItem(QIcon(":/default.png"), "New language of programming"));
}//on_addButton_clicked()

#define CURR_INDEX ui->listView->currentIndex()

void MainWindow::on_removeButton_clicked()
{
    if (CURR_INDEX.isValid())
        model_ex2->removeRow(model_ex2->itemFromIndex(CURR_INDEX)->row());
}//on_removeButton_clicked()

#define VIEW_MODE ui->listView->setViewMode

void MainWindow::on_checkBox_clicked()
{
    if (!(ui->checkBox->isChecked())) ui->listView->setViewMode(QListView::ListMode);
    else ui->listView->setViewMode(QListView::IconMode);
    ui->listView->setDragDropMode(QAbstractItemView::DragDrop);
    ui->listView->setDefaultDropAction(Qt::MoveAction);
}//on_checkBox_clicked()

/*********************** Ex. 3 ****************************/

void MainWindow::on_tableView_clicked(const QModelIndex &index)
{
    auto it = selected_row.find(index.row());
    if (it != selected_row.end()) {
        selected_row.erase(it);
        return;
    }//if (it != selected_row.end())
    selected_row.insert(index.row());
}//on_tableView_clicked(const QModelIndex &index)

void MainWindow::setBackgroundRow(const Qt::GlobalColor &color)
{
    for (auto i : selected_row)
        for (int j = 0; j < model_ex3->columnCount(); ++j)
            model_ex3->item(i,j)->setBackground(QBrush(color));
}//void MainWindow::setBackgroundRow(QColor &color)

void MainWindow::on_redButton_clicked()
{
    setBackgroundRow(Qt::red);
}//on_redButton_clicked()

void MainWindow::on_greenButton_clicked()
{
    setBackgroundRow(Qt::green);
}//on_greenButton_clicked()

void MainWindow::on_blueButton_clicked()
{
    setBackgroundRow(Qt::blue);
}//on_blueButton_clicked()

void MainWindow::on_grayButton_clicked()
{
    setBackgroundRow(Qt::gray);
}//on_grayButton_clicked()

void MainWindow::on_whiteButton_clicked()
{
    setBackgroundRow(Qt::white);
}//on_whiteButton_clicked()
