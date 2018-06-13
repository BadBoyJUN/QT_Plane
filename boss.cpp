#include "boss.h"

Boss::Boss()
{

}

Boss::Boss(QWidget *widget, int x, int y, int width, int height, int distance,int blood)
:enemy(widget,x,y,width,height,distance)
{
    this->blood = blood;
}

void Boss::To_move(int direction)
{
    enemy::To_move(direction);
}

void Boss::draw()
{
    enemy::draw();
}

void Boss::Fire()
{
    qDebug()<<"Boss发招了";
}

void Boss::drop()
{
    qDebug()<<"Boss的血量"<<blood;
    if(blood<0){
         qDebug()<<"Boss死了";
    }
}


