#include "bullet.h"

Bullet::Bullet()
{

}

Bullet::Bullet(QWidget *widget, int x, int y, int width, int height, int distance)
:plane(widget,x,y,width,height,distance)
{

}

void Bullet::To_move(int direction)
{
    y-=this->distance;
}

void Bullet::draw()
{
    //初始化子弹
    QRect rect = {
        x-width/2,y-height,width,height
    };

    QColor color(255,55,0);
    //初始化画笔父级窗口
    QPainter painter(this->parent);
    painter.setPen(color);//笔的颜色
    painter.setBrush(QBrush(color,Qt::Dense3Pattern));
    if(picture.isNull()){
        painter.drawRoundedRect(rect,40,40);
    }else {
        painter.drawPixmap(rect,picture);
    }

}

/**
 * @brief Bullet::drop
 * 子弹爆炸
 */
void Bullet::drop()
{
    qDebug()<<"敌人被击中坠毁了";
    if(is_drop){
        is_drop = false;
    }
}

