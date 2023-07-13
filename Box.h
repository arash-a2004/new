#ifndef BOX_H
#define BOX_H

#include <Qpixmap>
#include <QGraphicsPixmapItem>
class Box : public QGraphicsPixmapItem
{

private:
    int health;
public:
    explicit Box();
    bool chealth(int damage);
};

#endif // BOX_H
