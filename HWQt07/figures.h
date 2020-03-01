#ifndef FIGURES_H
#define FIGURES_H

#include <QGraphicsSceneMouseEvent>
#include <QGraphicsItem>
#include <QPainter>
#include <QCursor>
#include <QObject>
#include <QBrush>


class Figures : public QObject, public QGraphicsItem
{
    Q_OBJECT
    Q_PROPERTY(QBrush brush)
public:
    explicit Figures(QObject *parent = nullptr);
    void setBrush(QBrush b);
    void nextGeometry();
    bool getDel() const;

signals:
    void reDraw();
    void addFigure();
    void clicked();

private:
    void paint(QPainter *p, const QStyleOptionGraphicsItem *o, QWidget *w) override;
    QRectF boundingRect() const override;
    enum Geometry {RECTANGLE, CIRCLE, STAR};
    static Geometry geo;
    Geometry myG;
    int32_t x, y;
    QPoint point;
    QBrush brush;
    bool moving = false;
    bool rotate = false;
    bool del = false;

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override;

};//class Figures : public QObject, public QGraphicsItem
#endif // FIGURES_H
