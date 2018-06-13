#ifndef BULLET_H
#define BULLET_H
#include "plane.h"

/**
 * @brief The Bullet class
 * 子弹类
 */
class Bullet : public plane
{
public:
    Bullet();

    //初始化玩家参数(位置，大小)
    explicit Bullet(QWidget *widget, int x,int y, int width, int height , int distance);

    //移动子弹
    virtual void To_move(int direction);
    //画子弹
    virtual void draw();

    //子弹爆炸,以及特效显示
    virtual void drop();

};

#endif // BULLET_H
