#ifndef Boss_H
#define Boss_H

#include "enemy.h"
#include "bullet.h"


class Boss : public enemy
{
public:
    Boss();

    explicit Boss(QWidget *widget, int x ,int y , int width, int height , int distance, int blood);

    //移动Boss
    virtual void To_move(int direction);
    //画Boss
    virtual void draw();


    //Boss开火
    void Fire();
    //Boss坠毁
    virtual void drop();

public:
    int blood=1;

    bool isdisplay = false;
};

#endif // Boss_H
