#ifndef MAP_H
#define MAP_H

#include <QList>
#include <Box.h>
#include <Jungle.h>
#include <Wall.h>
class Map
{
private:
    QList <Box*>box;
    QList <Jungle*>jungle;
    QList <Wall *>wall;
public:
    Map();
    void Add_sth(int k,int x,int y,QGraphicsScene* scene);
};

#endif // MAP_H
