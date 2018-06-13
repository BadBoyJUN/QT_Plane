#ifndef PLAYERONE_H
#define PLAYERONE_H
#include "plane.h"
#include "bullet.h"

/**
 * @brief The PlayerOne class
 * 玩家类
 */
class PlayerOne: public plane
{
public:
    PlayerOne();

    //初始化玩家参数(父类窗口对象,位置，大小)
    explicit PlayerOne(QWidget *widget, int x,int y, int width, int height , int distance, QString bullet_picture
                       , int bullet_width, int bullet_height);

    //移动飞机
    virtual void To_move(int direction);
    //画飞机
    virtual void draw();
    //开火
    void Fire();
    //玩家坠毁
    virtual void drop();

    //子弹大小
    int bullet_width = 20;
    int bullet_height = 20;


    //发射的子弹
    QList<Bullet*> bullets;

private:
    //开火时间
    QTime fire_time = QTime::currentTime();
    //子弹图片路径
    QString bullet_picture = NULL ;

};

#endif // PLAYERONE_H
