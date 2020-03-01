#include "figures.h"

Figures::Geometry Figures::geo = Figures::RECTANGLE;

Figures::Figures(QObject *parent) : QObject(parent)
{
    x = y = 0;
    brush.setColor(QColor(rand()%256, rand()%256, rand()%256));
    brush.setStyle(Qt::BrushStyle::SolidPattern);
    setPos(0, 0);
    myG = geo;
    nextGeometry();
}//explicit Figures(QObject *parent = nullptr)

void Figures::setBrush(QBrush b)
{
    brush = b;
    emit reDraw();
}//void setBrush(QBrush b)

void Figures::nextGeometry()
{
    if (geo == RECTANGLE) geo = CIRCLE;
    else if (geo == CIRCLE) geo = STAR;
    else geo = RECTANGLE;
}//void nextGeometry()

bool Figures::getDel() const
{
    return del;
}//bool getDel() const

void Figures::paint(QPainter *p, const QStyleOptionGraphicsItem *o, QWidget *w)
{
    p->setBrush(brush);
    const QPointF star[10] = {
        QPointF(x-10, y-13.8),  QPointF(x, y-44.6),  QPointF(x+10, y-13.8),  QPointF(x+42.4, y-13.8),  QPointF(x+16.2, y+5.2),
        QPointF(x+26.2, y+36.0),  QPointF(x, y+17.0),  QPointF(x-26.2, y+36),  QPointF(x-16.2, y+5.2),   QPointF(x-42.4, y-13.8)
    };//star
    switch (myG) {
    case RECTANGLE:   p->drawRect(x, y, 100, 50);
        break;
    case CIRCLE:      p->drawEllipse(x, y, 50, 50);
        break;
    case STAR:        p->drawPolygon(star, 10);
        break;
    }//switch (geo)
    Q_UNUSED(o)
    Q_UNUSED(w)
}//void paint(QPainter *p, const QStyleOptionGraphicsItem *o, QWidget *w) override

QRectF Figures::boundingRect() const
{
    return QRectF(x-50, y-50, 200, 100);
}//QRectF boundingRect() const override

void Figures::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        moving = true;
        setCursor(QCursor(Qt::ClosedHandCursor));
    }//if (event->button() == Qt::LeftButton)
    if (event->button() == Qt::RightButton) {
        del = true;
        hide();
    }//if (event->button() == Qt::RightButton)
    if (event->button() == Qt::MidButton) {
        rotate = true;
    }//if (event->button() == Qt::MidButton)
}//void mousePressEvent(QGraphicsSceneMouseEvent *event) override

void Figures::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    if (event->button() == Qt::LeftButton) {
        moving = false;
        setCursor(QCursor(Qt::ArrowCursor));
        emit clicked();
    } else if (event->button() == Qt::MidButton)
        rotate = false;
}//void mouseReleaseEvent(QGraphicsSceneMouseEvent *event) override

void Figures::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    if (moving) {
        setPos(mapToScene(event->pos()));
        emit reDraw();
    }//if (moving)
    if (rotate){
        setRotation(mapToScene(event->pos()).rx());
    }
}//void mouseMoveEvent(QGraphicsSceneMouseEvent *event) override

