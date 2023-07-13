#include "View.h"

View::View()
{
    scene = new QGraphicsScene;
    scene->setSceneRect(0,0,810,390);
    setScene(scene);
    setBackgroundBrush(QBrush(QImage(":/images/menu.png")));
    setFixedSize(810,390);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//    QFile file(":/TXT files/Tank.txt");
//    QTextStream in(&file);
//    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
//    {
//        return;
//    }

//    QString line = in.readLine();
//    for(int j=0;j<line.size();j++)
//        qInfo()<<line[j];
    player1=new Tank("d1",3,20,3,0,"123",scene,1);
    player2=new Tank("d2",4,15,5,0,"124",scene,2);
    scene->addItem(player1);
    scene->addItem(player2);
    timer = new QTimer();
    timer->start(100);
    this->show();
}

void View::keyPressEvent(QKeyEvent * event) {
    if (keysPressed.contains(event->key())) return;
    keysPressed.insert(event->key());
    switch (event->key()) {
    case Qt::Key::Key_W:
        QObject::connect(timer, SIGNAL(timeout()), player1, SLOT(move_up()));
        break;
    case Qt::Key::Key_S:
        QObject::connect(timer, SIGNAL(timeout()), player1, SLOT(move_down()));
        break;
    case Qt::Key::Key_D:
        QObject::connect(timer, SIGNAL(timeout()), player1, SLOT(move_right()));
        break;
    case Qt::Key::Key_A:
        QObject::connect(timer, SIGNAL(timeout()), player1, SLOT(move_left()));
        break;
    case Qt::Key::Key_Up:
        QObject::connect(timer, SIGNAL(timeout()), player2, SLOT(move_up()));
        break;
    case Qt::Key::Key_Down:
        QObject::connect(timer, SIGNAL(timeout()), player2, SLOT(move_down()));
        break;
    case Qt::Key::Key_Right:
        QObject::connect(timer, SIGNAL(timeout()), player2, SLOT(move_right()));
        break;
    case Qt::Key::Key_Left:
        QObject::connect(timer, SIGNAL(timeout()), player2, SLOT(move_left()));
        break;
    case Qt::Key::Key_K:
        QObject::connect(timer, SIGNAL(timeout()), player2, SLOT(shoot()));
        break;
    case Qt::Key::Key_C:
        QObject::connect(timer, SIGNAL(timeout()), player1, SLOT(shoot()));
        break;
    default:
        break;
    }
}

void View::keyReleaseEvent(QKeyEvent *event) {
    keysPressed.remove(event->key());
    switch (event->key()) {
    case Qt::Key::Key_W:
        QObject::disconnect(timer, SIGNAL(timeout()), player1, SLOT(move_up()));
        break;
    case Qt::Key::Key_S:
        QObject::disconnect(timer, SIGNAL(timeout()), player1, SLOT(move_down()));
        break;
    case Qt::Key::Key_D:
        QObject::disconnect(timer, SIGNAL(timeout()), player1, SLOT(move_right()));
        break;
    case Qt::Key::Key_A:
        QObject::disconnect(timer, SIGNAL(timeout()), player1, SLOT(move_left()));
        break;
    case Qt::Key::Key_Up:
        QObject::disconnect(timer, SIGNAL(timeout()), player2, SLOT(move_up()));
        break;
    case Qt::Key::Key_Down:
        QObject::disconnect(timer, SIGNAL(timeout()), player2, SLOT(move_down()));
        break;
    case Qt::Key::Key_Right:
        QObject::disconnect(timer, SIGNAL(timeout()), player2, SLOT(move_right()));
        break;
    case Qt::Key::Key_Left:
        QObject::disconnect(timer, SIGNAL(timeout()), player2, SLOT(move_left()));
        break;
    case Qt::Key::Key_K:
        QObject::disconnect(timer, SIGNAL(timeout()), player2, SLOT(shoot()));
        break;
    case Qt::Key::Key_C:
        QObject::disconnect(timer, SIGNAL(timeout()), player1, SLOT(shoot()));
        break;
    default:
        break;
    }
}

QGraphicsScene *View::get_scene()
{
    return scene;
}

View::~View()
{
    delete scene;
    delete player1;
    delete player2;
}
