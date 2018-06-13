#ifndef ENEMY_H
#define ENEMY_H
#include "plane.h"

/**
 * @brief The enemy class
 * 敌人类
 */
class enemy : public plane
{
public:
    enemy();

    explicit enemy(QWidget *widget, int x ,int y , int width, int height , int distance);


    //移动飞机
    virtual void To_move(int direction);
    //画飞机
    virtual void draw();

    //敌人坠毁,以及特效显示
    virtual void drop();

Q_SIGNALS:
    void Add_Score(qint32);


private:



};

#endif // ENEMY_H
