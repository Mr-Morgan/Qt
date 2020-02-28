#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    path = new QLineEdit (this);

    ui->toolBar->addAction(ui->actionBack);
    ui->toolBar->addAction(ui->actionForward);
    ui->toolBar->addWidget(path);
    ui->toolBar->addAction(ui->actionSearch);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionView);
    ui->toolBar->addAction(ui->actionDayNight);
    ui->toolBar->addAction(ui->actionSettings);
    ui->toolBar->addAction(ui->actionFullScreen);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionAbout);
    ui->toolBar->addSeparator();
    ui->toolBar->addAction(ui->actionExit);

    model = new QFileSystemModel (this);
    model->setFilter(QDir::AllEntries | QDir::NoDot);
    model->setRootPath("/home");

    ui->favour->setFrameStyle(QFrame::NoFrame);
    ui->favour->setIconSize(QSize(32, 32));
    ui->favour->setGridSize(QSize(80, 50));

    ui->listView->setModel(model);
    ui->listView->setRootIndex(model->index("/home"));
    ui->listView->setResizeMode(QListView::Adjust);
    ui->listView->setIconSize(QSize(46, 46));
    ui->listView->setGridSize(QSize(100, 70));
    ui->listView->setDragDropMode(QAbstractItemView::NoDragDrop);

    path->setText(model->rootPath());
    connect(path, SIGNAL(returnPressed()), this, SLOT(on_path_returnPressed()));
}//MainWindow(QWidget *parent = nullptr)

void MainWindow::pushChanges(QStack<QString> &st, QString ch)
{
    if (st.count() == STACK_MAX_SIZE) st.pop_front();
    st.push(ch);
}//void pushChanges(QStack<QString> &st, QString &ch)

MainWindow::~MainWindow()
{
    delete ui;
}//~MainWindow()

void MainWindow::on_actionFullScreen_triggered()
{
    if (isFullScreen()) {
        showNormal();
        ui->actionFullScreen->setIcon(QIcon(":/icons/fullScreen.png"));
    } else {
        showFullScreen();
        ui->actionFullScreen->setIcon(QIcon(":/icons/fullScreenOff.png"));
    }//if (isFullScreen())
}//on_actionFullScreen_triggered()

void MainWindow::on_actionExit_triggered()
{
    close();
}//on_actionExit_triggered()

void MainWindow::on_listView_doubleClicked(const QModelIndex &index)
{
    QFileInfo info = model->fileInfo(index);
    if (info.isDir()) {
        if (info.fileName() == "..") {
            QDir d = info.dir();
            d.cdUp();
            ui->listView->setRootIndex(model->index(d.absolutePath()));
        } else ui->listView->setRootIndex(index);
        path->setText(info.absoluteFilePath());
        pushChanges(back, info.path());
    }//if (info.isDir())
}//on_listView_doubleClicked(const QModelIndex &index)

void MainWindow::on_path_returnPressed()
{
    ui->listView->setRootIndex(model->index(path->text()));
}//on_path_returnPressed()

void MainWindow::on_actionView_triggered()
{
    if (ui->listView->viewMode() == QListView::ViewMode::IconMode) {
        ui->listView->setViewMode(QListView::ViewMode::ListMode);
        ui->actionView->setIcon(QIcon(":/icons/list.png"));
    } else {
        ui->listView->setViewMode(QListView::ViewMode::IconMode);
        ui->actionView->setIcon(QIcon(":/icons/icons2.png"));
    }//if (ui->listView->viewMode() == QListView::ViewMode::IconMode)
}//on_actionView_triggered()

void MainWindow::on_actionBack_triggered()
{
    if (back.count()) {
        ui->listView->setRootIndex(model->index(back.top()));
        path->setText(model->fileInfo(model->index(back.top())).absoluteFilePath());
        pushChanges(forvard, back.pop());
    }//if (back.count())
}//on_actionBack_triggered()

void MainWindow::on_actionForward_triggered()
{
    if (forvard.count()) {
        ui->listView->setRootIndex(model->index(forvard.top()));
        path->setText(model->fileInfo(model->index(forvard.top())).absoluteFilePath());
        pushChanges(back, forvard.pop());
    }//if (forvard.count())
}//on_actionForward_triggered()

void MainWindow::on_actionAbout_triggered()
{
    QFile file(":/about.txt");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::information(this, "О программе", file.readAll());
        file.close();
    }//if (file.open(QIODevice::ReadOnly | QIODevice::Text))
}//on_actionAbout_triggered()

void MainWindow::on_favour_clicked(const QModelIndex &index)
{
    on_listView_doubleClicked(index);
}//on_favour_clicked(const QModelIndex &index)
