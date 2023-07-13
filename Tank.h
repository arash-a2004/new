#ifndef TANK_H
#define TANK_H

#include <QObject>
#include <Qpixmap>
#include <QGraphicsPixmapItem>
#include <QKeyEvent>
#include <Box.h>
#include <Jungle.h>
#include <Wall.h>
#include <QList>
#include <Bullet.h>
#include <QTime>

class Tank : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int damage,health,speed,angle,num;
    QString tank_Id,type;
    QGraphicsScene *scene;
    QList <Bullet *> bullets;
    QTimer *time;
public:
    bool ending=false;
    explicit Tank(QString Type,int Damage,int Health,int Speed,int Angle,QString Tank_Id,QGraphicsScene *Scene,int Num);
    bool Is_obj();
    void D_health(int dam);
signals:

public slots:
    void move_up();
    void move_down();
    void move_right();
    void move_left();
    void shoot();
};

#endif // TANK_H
