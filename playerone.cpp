#include "playerone.h"

PlayerOne::PlayerOne()
{

}

PlayerOne::PlayerOne(QWidget *widget, int x, int y, int width, int height, int distance, QString bullet_picture
                     , int bullet_width, int bullet_height)
    :plane(widget,x,y,width,height,distance)
{
    this->bullet_picture = bullet_picture;
    this->bullet_width = bullet_width;
    this->bullet_height = bullet_height;
}
//移动飞机
void PlayerOne::To_move(int direction)
{
    switch (direction) {
    case Qt::Key_Up:
        if(this->y >= 0){
            this->y-=this->distance;
        }
        break;

    case Qt::Key_Left:
        if(this->x-this->width/2 >= 0){
            this->x-=this->distance;
        }
        break;

    case Qt::Key_Down:
        if(this->y+this->height/2 <= this->parent->height()){
            this->y+=this->distance;
        }
        break;

    case Qt::Key_Right:
        if(this->x+this->width/2 <= this->parent->width()){
            this->x+=this->distance;
        }
        break;

    case Qt::Key_Space:
        QTime interval_time = QTime::currentTime();
        if(fire_time.msecsTo(interval_time)>200){
            qDebug()<<"发射子弹";
            fire_time = interval_time;//重置开火时间
            this->Fire();
        }
        break;
    }
}

//画飞机
void PlayerOne::draw()
{
    //初始化飞机(x,y为飞机头部顶点)
    QPointF points[3] = {QPointF(x,y)
                         ,QPointF(x-width/2,y+height)
                         ,QPointF(x+width/2,y+height)};

    QColor color(255,255,0);
    //初始化画笔父级窗口
    QPainter painter(this->parent);
    painter.setPen(color);//笔的颜色
    painter.setBrush(QBrush(color,Qt::Dense3Pattern));

    if(picture.isNull()){
        painter.drawPolygon(points,3);
    }else {
        painter.drawPixmap(x-width/2,y,width,height,picture);
    }


}

//飞机开火
void PlayerOne::Fire()
{
    //添加静态子弹参数
    Bullet *bullet = new Bullet(this->parent,x,y,bullet_width,bullet_height,5);
    bullet->LoadingPicture(bullet_picture);
    bullets.append(bullet);
}

/**
 * @brief PlayerOne::drop
 * 玩家坠毁
 */
void PlayerOne::drop()
{

    if(is_drop){
        qDebug()<<"玩家被击中坠毁了";
                is_drop = false;
    }
}




