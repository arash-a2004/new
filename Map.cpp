#include "Map.h"
#include "Wall.h"
#include "qgraphicsscene.h"

Map::Map()
{

}

void Map::Add_sth(int k,int x,int y,QGraphicsScene* scene)
{
    if(k==1)
    {
        auto *wl=new Wall;
        wl->setPos(x,y);
        scene->addItem(wl);
        wall.push_front(wl);
    }
    else if(k==2)
    {
       auto *bx=new Box;
       bx->setPos(x,y);
       scene->addItem(bx);
       box.push_front(bx);
    }
    else if(k==3)
    {
       auto *jg=new Jungle;
       jg->setPos(x,y);
       scene->addItem(jg);
       jungle.push_front(jg);
    }
}
