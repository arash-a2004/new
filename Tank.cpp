#include "Tank.h"
#include "qgraphicsscene.h"
#include "qtimer.h"

Tank::Tank(QString Type, int Damage, int Health, int Speed, int Angle, QString Tank_Id, QGraphicsScene *Scene, int Num):damage(Damage)
    ,health(Health),speed(Speed),angle(Angle),num(Num),tank_Id(Tank_Id),type(Type),scene(Scene)
{
   if(num==1)
   {
    setPos(50,50);
    setPixmap(QPixmap(":/images/greenright.png"));
   }
   else
   {
    setPos(730,310);
    setPixmap(QPixmap(":/images/redleft.png"));
   }
   setFlag(ItemIsFocusable);
   setFocus();
   time=new QTimer;
   time->start(100);
}

bool Tank::Is_obj()
{
   QList<QGraphicsItem *> colliding_items = collidingItems();
   for (int i = 0; i < colliding_items.size(); ++i)
   {
    if (typeid(*(colliding_items[i])) == typeid(Box) || typeid(*(colliding_items[i])) == typeid(Wall) || typeid(*(colliding_items[i])) == typeid(Jungle) || typeid(*(colliding_items[i])) == typeid(Tank))
    {
        return true;
    }
   }
   return false;

}

void Tank::D_health(int dam)
{
   health-=dam;
   if(health<=0)
    ending=true;
}

void Tank::move_up()
{
   setPos(x(),y()-1);
   while(Is_obj())
   {
     setPos(x(),y()+1);
   }
   if(!Is_obj())
   {
     if(num == 1)
       setPixmap(QPixmap(":/images/greenup.png"));
     else
       setPixmap(QPixmap(":/images/redup.png"));
     angle=3;
   }
   qInfo()<<"11";
}
void Tank::move_down()
{
    setPos(x(),y()+1);
   while(Is_obj())
    {
      setPos(x(),y()-1);
    }
    if(!Is_obj())
    {
     if(num == 1)
       setPixmap(QPixmap(":/images/greendown.png"));
     else
       setPixmap(QPixmap(":/images/reddown.png"));
     angle=4;
    }
    qInfo()<<"12";
}

void Tank::move_right()
{
    setPos(x()+1,y());
    while(Is_obj())
    {
      setPos(x()-1,y());
    }
    if(!Is_obj())
    {
     if(num == 1)
       setPixmap(QPixmap(":/images/greenright.png"));
     else
       setPixmap(QPixmap(":/images/redright.png"));
     angle=1;
    }
    qInfo()<<"13";
}

void Tank::move_left()
{
    setPos(x()-1,y());
    while(Is_obj())
    {
      setPos(x()+1,y());
    }
    if(!Is_obj())
    {
     if(num == 1)
       setPixmap(QPixmap(":/images/greenleft.png"));
     else
       setPixmap(QPixmap(":/images/redleft.png"));
     angle=2;
    }
    qInfo()<<"14";
}

void Tank::shoot()
{
    auto *blt = new Bullet(damage,angle,scene);
    scene->addItem(blt);
    if(angle == 1)
      blt->setPos(x()+40,y());
    else if(angle == 2)
      blt->setPos(x()-40,y());
    else if(angle == 3)
      blt->setPos(x(),y()-40);
    else if(angle == 4)
      blt->setPos(x(),y()+40);
    QObject::connect(time,SIGNAL(timeout()),blt,SLOT(move()));
    bullets.push_front(blt);
}

