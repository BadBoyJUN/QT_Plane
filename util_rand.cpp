#include "util_rand.h"
#include <QtGlobal>
#include <time.h>
#include <QTime>


Util_Rand::Util_Rand()
{
    //初始化随机数种子
    qsrand(time(0));
}

int Util_Rand::rand(int num)
{
    int rand_num = qrand()%num;
    return rand_num;
}



