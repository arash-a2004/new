#ifndef VIEW_H
#define VIEW_H
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QSet>
#include <QDebug>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsRectItem>
#include <Tank.h>
#include <QFile>
class View:public QGraphicsView
{
    Q_OBJECT
private:
    QGraphicsScene *scene;
    void handlePlayer1(int direction);
    void handlePlayer2(int direction);
    QSet<int> keysPressed;
    QTimer * timer;

protected:
   void keyPressEvent(QKeyEvent *event);
   void keyReleaseEvent(QKeyEvent *event);
public:
    Tank *player1;
    Tank *player2;
    View();
    QGraphicsScene* get_scene();
    ~View();
};

#endif // VIEW_H
