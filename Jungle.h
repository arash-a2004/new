#ifndef JUNGLE_H
#define JUNGLE_H

#include <Qpixmap>
#include <QGraphicsPixmapItem>

class Jungle : public QGraphicsPixmapItem
{

private:

public:
    explicit Jungle();

};

#endif // JUNGLE_H
//QList<QGraphicsItem *> colliding_items = player->collidingItems();
//for (int i = 0; i < colliding_items.size(); ++i)
//{
//    if (typeid(*(colliding_items[i])) == typeid(Enemy))
//    {
//        // remove enemy
//    }
//}
