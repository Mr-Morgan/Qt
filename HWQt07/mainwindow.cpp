#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QGraphicsView(parent)
{
    srand(static_cast<unsigned>(clock()));
    scene = new QGraphicsScene(this);
    setScene(scene);
    addFigure();
}//MainWindow(QWidget *parent = nullptr)

MainWindow::~MainWindow()
{

}//~MainWindow()

void MainWindow::reDraw()
{
    for (int i = 0; i < figures.size(); ++i)
        if (figures.at(i)->getDel()) {
            delete figures.at(i);
            figures.removeAt(i);
        }//if (figures.at(i)->getDel())
    for (auto f : figures)
        if (!(f->getDel()))
            scene->addItem(f);
    scene->update();
    update();
}//void reDraw()

void MainWindow::addFigure()
{
    Figures *f = new Figures (this);
    connect(f, SIGNAL(reDraw()), this, SLOT(reDraw()));
    connect(f, SIGNAL(clicked()), this, SLOT(view_clicked()));
    scene->addItem(f);
    figures.push_back(f);
}//void addFigure()

void MainWindow::view_clicked()
{
    addFigure();
    reDraw();
}//void view_clicked()

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Plus) {
        scale(1.1, 1.1);
    }
    if (event->key() == Qt::Key_Minus) {
        scale(1/1.1, 1/1.1);
    }
}//void keyReleaseEvent(QKeyEvent *event) override
