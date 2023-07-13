#ifndef BULLET_H
#define BULLET_H

#include <QObject>
#include <Qpixmap>
#include <QGraphicsPixmapItem>
#include <Box.h>
class Bullet : public QObject,public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int Damage,Speed,direct;
    QGraphicsScene *scene;
public:
    explicit Bullet(int d,int di,QGraphicsScene *scene);

signals:

public slots:
    void move();
};

#endif // BULLET_H
