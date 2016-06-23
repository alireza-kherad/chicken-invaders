#include "bullet.h"
#include <QGraphicsScene>

bullet::bullet(qreal bulletAngel)
{
    setPixmap(QPixmap(":img/bullet.png"));
    speed = 10;
    angle = bulletAngel - 90;
    setRotation(angle);
}

void bullet::advance(int phase)
{
    if(!phase)
        return;

    if(x() > 1200 || y() < 0){
        scene()->removeItem(this);
        delete this;
    }

    QList<QGraphicsItem *> items = collidingItems();
    for(int i=0 ; i<items.size() ;i++)
    {
        if(typeid(*(items[i])) == typeid(Bird))
        {
            scene()->removeItem(items[i]);
            delete(items[i]);

            scene()->removeItem(this);
            delete this;
        }
    }

    //QPointF location = this->pos();
    setPos(mapToParent(0, -speed));
}

