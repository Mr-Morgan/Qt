#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QMouseEvent>

#include "figures.h"

class MainWindow : public QGraphicsView
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private:
    QGraphicsScene *scene;
    QVector<Figures*> figures;

private slots:
    void reDraw();
    void addFigure();
    void view_clicked();

protected:
    void keyReleaseEvent(QKeyEvent *event) override;
};//class MainWindow : public QGraphicsView
#endif // MAINWINDOW_H
