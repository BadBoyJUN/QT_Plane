#include "enemy.h"

enemy::enemy()
{

}

//构造敌人
enemy::enemy(QWidget *widget, int x, int y, int width, int height, int distance)
    :plane(widget,x,y,width,height,distance)
{

}

void enemy::To_move(int direction)
{
    this->y += this->distance;
}

void enemy::draw()
{
    QColor color(255,0,255);
    //初始化画笔父级窗口
    QPainter painter(this->parent);
    painter.setPen(color);//笔的颜色
    painter.setBrush(QBrush(color,Qt::Dense3Pattern));

    if(picture.isNull()){
        //如果没有读取到图片
        QPointF points[3] = {QPointF(x,y),QPointF(x+15,y+30),QPointF(x+30,y)};
        painter.drawPolygon(points,3);
    }else{
        painter.drawPixmap(x,y,width,height,picture);
    }

}

/*
 * 敌人坠毁
 * */
void enemy::drop()
{
    qDebug()<<"敌人被击中坠毁了";
    if(is_drop){
        is_drop = false;
    }
//    deleteLater();
    //爆炸animation

    //发送信号，游戏界面分数增加
//    emit Add_Score(1);
}

