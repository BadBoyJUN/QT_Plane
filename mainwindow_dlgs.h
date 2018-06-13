#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "plane.h"
#include <QTimer>
#include <QTimerEvent>
#include "playerone.h"
#include "enemy.h"
#include "boss.h"
#include "util_rand.h"


#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    explicit MainWindow(QWidget *parent = 0, int enemys_score=1, int enemys_speed=1, int bullet_width = 20,
    int bullet_height = 20);

    ~MainWindow();


    virtual void paintEvent(QPaintEvent *event);
    virtual void keyPressEvent(QKeyEvent *event);

private:
    Ui::MainWindow *ui;

    enemy * enemy_connect;
    void init();

    //背景音乐
    QMediaPlayer media;

    //玩家
    PlayerOne *player;
    //敌人
    QList<enemy*> enemys;
    //敌人迭代器
    QList<enemy*>::const_iterator enemys_it;
    //敌人飞机大小
    int enemys_width = 50;
    int enemys_height = 50;
    //敌人出现的位置(左上角)
    int enemys_X = 0;
    int enemys_Y = 0;
    //敌人飞行
    int enemys_speed = 1;
    //敌人图片
    QString enemys_Picture_Str = ":/picture/picture/enemy.png";
    //Boss指针
    Boss *boss;
    //Boss图片
    QString Boos_Picture_Str = ":/picture/picture/enemy2.png";

    //敌人飞机大小
    int Boss_width = 800;
    int Boss_height = 300;
    //敌人出现的位置(左上角)
    int Boss_X = 100;
    int Boss_Y = 0;


    //子弹大小
    int bullet_width = 20;
    int bullet_height = 20;
    //子弹迭代器
    QList<Bullet*>::const_iterator bullet_it;

    //随机工具类
    Util_Rand ran;

    //定时器ID
    int time_ID;



    //定时器变量++（++后*间隔，每秒刷新一个敌人）
    int time_num=0;
    //定时器间隔时间
    int Time_interval = 10;
    //真实时间
    int Real_Time = 0;

    //初始化分数
    int score = 0;

    //第一关飞机数量
    int enemys_One_num = 100;
    //第一关飞机每隔两秒出现的
    int enemys_One = 2;
    //敌人分数
    int enemys_score = 1;

    //0为游戏通关，1为玩家死亡
    int Pass_Parameter  = 0;

    void Update_score(int add_score);

Q_SIGNALS:
    void Return_Score(QString);

protected:
     void closeEvent(QCloseEvent *event);

private slots:
    virtual void timerEvent( QTimerEvent *event);

};

#endif // MAINWINDOW_H
