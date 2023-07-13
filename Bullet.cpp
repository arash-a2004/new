#include "Bullet.h"
#include "Box.h"
#include "Tank.h"
#include "Wall.h"
#include "qgraphicsscene.h"

Bullet::Bullet(int d, int di, QGraphicsScene *S)
    : QObject{},Damage(d),Speed(10),direct(di),scene(S)
{
    setPixmap(QPixmap(":/images/tinywow_change_bg_photo_28741302.png"));
}

void Bullet::move()
{
    QList<QGraphicsItem *> colliding_items = collidingItems();
    int n2=1;
    for (int i = 0; i < colliding_items.size(); ++i)
    {
        if (scene!=NULL && typeid(*(colliding_items[i])) == typeid(Box))
        {
            qInfo()<<"1";
            Box *temp=dynamic_cast<Box *>(colliding_items[i]);
            bool n = temp->chealth(Damage);
            if(n)
            {
                scene->removeItem(temp);
                delete temp;
            }
            n2=0;
            scene->removeItem(this);
            delete this;
            return;
        }
        else if(scene!=NULL && typeid(*(colliding_items[i])) == typeid(Tank))
        {
            qInfo()<<"5";
            Tank *temp=dynamic_cast<Tank *>(colliding_items[i]);
            temp->D_health(Damage);
            n2=0;
            scene->removeItem(this);
            delete this;
            return;
        }
        else if(scene!=NULL && typeid(*(colliding_items[i])) == typeid(Wall))
        {
            qInfo()<<"2";
            n2=0;
            scene->removeItem(this);
            delete this;
            return;
        }
    }
    if(direct == 1)
        setPos(x() + Speed,y());
    else if(direct == 2)
        setPos(x() - Speed,y());
    else if(direct == 3)
        setPos(x(),y() - Speed);
    else if(direct == 4)
        setPos(x(),y() + Speed);

    if(n2 && (x()<=0 || x()>=810 || y()<=0 || y()>=390))
    {
        qInfo()<<"3";
        scene->removeItem(this);
        delete this;
    }
}
