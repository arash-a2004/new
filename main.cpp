#include <QApplication>
#include "View.h"
#include <QGraphicsRectItem>
#include <QGraphicsSimpleTextItem>
#include <QPushButton>
#include <QFont>
#include <QObject>
#include <iostream>
#include <QBrush>
#include <Map.h>
void Make_map(View *vgame);
void Menu(View *);
void Make_map(View *vgame);
void play();
View *vgame;
Map *a=new Map;
QPushButton *button ;
QPushButton *button2 ;
QPushButton *button3 ;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto *vg=new View();
    vgame=vg;
    Menu(vgame);
    return a.exec();
}
void play()
{
    vgame->setBackgroundBrush(QBrush(QImage(":/images/bgc.png")));
    Make_map(vgame);
    vgame->show();
    button->deleteLater();
    button2->deleteLater();
    button3->deleteLater();
    delete button;
    delete button2;
    delete button3;
//        if(vgame->player1->ending)
//            Menu(vgame);
//        if(vgame->player2->ending)
//            Menu(vgame);
}
void Make_map(View *vgame)
{
    QFile file(":/TXT files/map_3.txt");
    QTextStream in(&file);
    int col=0,row=0;
    if(!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        return;
    }
    while(!in.atEnd())
    {
        QString Line = in.readLine();
        for(int i=0;i<Line.size();i++)
        {
            if(Line[i] == '1')
            {
                a->Add_sth(1,col * 15,row * 30 ,vgame->get_scene());
            }
            else if(Line[i] == '2')
            {
                a->Add_sth(2,col * 15,row * 30 ,vgame->get_scene());
            }
            else if(Line[i] == '3')
            {
                a->Add_sth(3,col * 15,row * 30 ,vgame->get_scene());
            }
            col++;
        }
        row++;
        col=0;
    }
}
void NewTank()
{
}
void Exit() {
    delete a;
    delete vgame;
    delete button;
    delete button2;
    delete button3;
    exit(1);
}
void Menu(View *vgame){
    //rect1->setBrush(QBrush(QColor(191, 191, 191)));
    button = new QPushButton("play");
    button->setStyleSheet("background-color: gray; color: white; font-size: 20px; padding-bottom: 20px; text-align: center;");
    button->setGeometry(202, 55, 404,55);
    QObject::connect(button, &QPushButton::clicked,play);
    vgame->get_scene()->addWidget(button);

    button2 = new QPushButton("new tank");
    button2->setStyleSheet("background-color: gray; color: white; font-size: 20px; padding-bottom: 20px; text-align: center;");
    button2->setGeometry(202, 165, 404,55);
    QObject::connect(button2, &QPushButton::clicked, NewTank);
    vgame->get_scene()->addWidget(button2);

    button3 = new QPushButton("Exit");
    button3->setStyleSheet("background-color: gray; color: white; font-size: 20px; padding-bottom: 20px; text-align: center;");
    button3->setGeometry(202, 275, 404,55);
    QObject::connect(button3, &QPushButton::clicked, Exit);
    vgame->get_scene()->addWidget(button3);
    vgame->show();
}
