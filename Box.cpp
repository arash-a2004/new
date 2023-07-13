#include "Box.h"

Box::Box()
    : health(10)
{
    setPixmap(QPixmap(":/images/box.jpg"));
}

bool Box::chealth(int damage)
{
    health-=damage;
    if(health<=0)
        return true;
    return false;
}
