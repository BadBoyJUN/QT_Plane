#include "mainwindow_dlgs.h"
#include "ui_mainwindow.h"
#include <QCloseEvent>





/**
 * @brief MainWindow::MainWindow
    画背景
    画飞机
    画敌人
    画子弹
    碰撞检测
    画分数
 */


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);
    init();
}

MainWindow::MainWindow(QWidget *parent, int enemys_score, int enemys_speed,
    int bullet_width, int bullet_height):
        QMainWindow(parent),
        ui(new Ui::MainWindow)
{
    this->setAttribute(Qt::WA_DeleteOnClose, true);
    ui->setupUi(this);

    this->enemys_score = enemys_score;
    this->enemys_speed = enemys_speed;
    this->bullet_width = bullet_width;
    this->bullet_height = bullet_height;
    init();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::init()
{

    //背景音乐
    //      media = new QMediaPlayer;
    //      connect(media, SIGNAL(positionChanged(qint64)), this, SLOT(positionChanged(qint64)));
    //      media->setMedia(QUrl::fromLocalFile("/Users/me/Music/coolsong.mp3"));
    //      media->setVolume(50);
    //      media->play();

    //分数信号连接
    //        QObject::connect(enemy_connect,SIGNAL(Add_Score(qint32)),
    //                this,SLOT(Update_score(qint32)));
    //        QObject::connect(enemy_connect,&enemy::Add_Score,
    //                   this,&MainWindow::Update_score);

    //初始化Boss
    boss = new Boss(this,Boss_X,Boss_Y,Boss_width,Boss_height,1,5);
    boss->LoadingPicture(Boos_Picture_Str);

    //玩家
    //飞机大小
    int player_width = 40;
    int player_height = 40;
    //玩家出现的位置(中间)
    int player_X = 1000/2;
    int player_Y = 700-player_height;
    //玩家飞行
    int player_speed = 10;
    //玩家图片
    QString player_Picture_Str= ":/picture/picture/PlayerOne.png";

    //子弹
    //子弹图片
    QString bullet_picture = ":/picture/picture/bullet.jpg";


    //初始化飞机
    player = new PlayerOne(this,player_X,player_Y,player_width,player_height,player_speed,bullet_picture
                           ,bullet_width,bullet_height);
    player->LoadingPicture(player_Picture_Str);
    //随机 初始化敌机
    enemy *en;

    for(int i = 0; i < enemys_One_num/20; i++){
        enemys_One_num -= enemys_One_num/20;
        int enemys_X = ran.rand(this->width()-enemys_width);
        en = new enemy(this,enemys_X,enemys_Y,enemys_width,enemys_height,enemys_speed);
        en->LoadingPicture(enemys_Picture_Str);
        enemys.append(en);
        qDebug()<<"敌人出现的X的位置："<<enemys_X;
    }

    //连接槽计时器
    time_ID = this->startTimer(Time_interval);
}

//重绘图像
void MainWindow::paintEvent(QPaintEvent *event)
{
    //画敌人
    //    int enemy_num = 0;
    for(enemys_it = enemys.constBegin(); enemys_it != enemys.constEnd(); enemys_it++){
        //判断该敌机是否被碰撞过
        if((*enemys_it)->isdrop()){
            (*enemys_it)->draw();
            //敌机和玩家的碰撞检测
            if((player->y >= (*enemys_it)->y&&
                    player->y <= (*enemys_it)->y+(*enemys_it)->height&&
                    player->x <= (*enemys_it)->x+(*enemys_it)->width&&
                        player->x >= (*enemys_it)->x )||(player->y >= (*enemys_it)->y&&
                        player->y <= (*enemys_it)->y+(*enemys_it)->height&&
                        player->x+player->width <= (*enemys_it)->x+(*enemys_it)->width&&
                        player->x+player->width >= (*enemys_it)->x)){
                       //玩家被摧毁
                    player->drop();
                }
            }
        }

    //画Boss
    if(boss->isdisplay){
        if(boss->isdrop()){
            boss->draw();
        }
    }

    //玩家
    if(player->isdrop()){//被摧毀检测
        player->draw();
    }else {
        this->close();
        qDebug()<<"头号玩家被摧毁，游戏结束";
    }


    //画子弹
    for(bullet_it = player->bullets.constBegin(); bullet_it!=player->bullets.constEnd(); bullet_it++){
        //子弹向上飞
        if((*bullet_it)->isdrop()){
            (*bullet_it)->draw();
        }


        //画敌人
        for(enemys_it = enemys.constBegin(); enemys_it != enemys.constEnd(); enemys_it++){
            if((*enemys_it)->isdrop()){//敌机是否可以被坠毁
                //碰撞检测(问题，会打到过去了的敌人 要改进判断)
                if(((*bullet_it)->y <= (*enemys_it)->y+(*enemys_it)->height)){//子弹头高度小于敌人最长高度时候
                    if((*bullet_it)->isdrop()){//子弹是否可以被坠毁
                        //子弹宽度左边或右边大于敌人宽度左右
                        if(((*bullet_it)->x-(*bullet_it)->width/2 >= (*enemys_it)->x &&
                            (*bullet_it)->x-(*bullet_it)->width/2 <= (*enemys_it)->x+(*enemys_it)->width )||
                                ((*bullet_it)->x+(*bullet_it)->width/2 >= (*enemys_it)->x &&
                                 (*bullet_it)->x+(*bullet_it)->width/2 <= (*enemys_it)->x+(*enemys_it)->width) ){
                            (*bullet_it)->drop();
                            (*enemys_it)->drop();
                            Update_score(enemys_score);
                        }
                    }
                }
            }
            else if (boss->isdisplay) {
                if(boss->isdrop()){//敌机是否可以被坠毁
                    //碰撞检测
                    if(((*bullet_it)->y <= boss->y+boss->height)){//子弹头高度小于敌人最长高度时候
                        if((*bullet_it)->isdrop()){//子弹是否可以被坠毁
                            //子弹宽度左边或右边大于敌人宽度左右
                            if(((*bullet_it)->x-(*bullet_it)->width/2 >= boss->x &&
                                (*bullet_it)->x-(*bullet_it)->width/2 <= boss->x+boss->width )||
                                    ((*bullet_it)->x+(*bullet_it)->width/2 >= boss->x &&
                                     (*bullet_it)->x+(*bullet_it)->width/2 <= boss->x+boss->width) ){
                                //boss减去血量
                                boss->blood-=1;
                                (*bullet_it)->drop();
                                //boss血量空了的时候
                                if(boss->blood<=0){
                                    boss->drop();
                                    Update_score(enemys_score*10);
                                    Pass_Parameter = 1;
                                    this->close();
                                }
                            }
                        }
                    }
                }
            }
        }
        update();
    }

}

//游戏界面的按键传递
void MainWindow::keyPressEvent(QKeyEvent *event)
{
    player->To_move(event->key());
    update();
}



/*定时器
 * QObject类提供的基本定时器
 * startTimer()、
 * timeEvent()、
 * killTimer()。
 * */
void MainWindow::timerEvent(QTimerEvent *event)
{


    if(event->timerId() == time_ID){
        //        qDebug()<< "计时器在动";
        time_num++;
        enemy *en;
        if(enemys_One_num>=0){ //小敌人数量还有的时候
            if((time_num*Time_interval)==2000){
                time_num=0;
                for(int i = 0;i<enemys_One;i++){
                    enemys_One_num-=enemys_One;
                    int enemys_X = ran.rand(this->width()-enemys_width);
                    en = new enemy(this,enemys_X,enemys_Y,enemys_width,enemys_height,enemys_speed);
                    en->LoadingPicture(enemys_Picture_Str);
                    enemys.append(en);
                }

            }
        }else{//开始打Boss
            boss->isdisplay = true;
        }

        //敌人向下移动
        for(int i = 0; i < enemys.length(); i++){
            enemys[i]->To_move(2);
            update();
        }

        //显示子弹并且移动
        //        qDebug()<<"子弹总数目为："<<player->bullets.length();
        for(bullet_it = player->bullets.constBegin(); bullet_it!=player->bullets.constEnd(); bullet_it++){
            //子弹向上飞
            (*bullet_it)->To_move(2);
            update();
        }

    }
}

void MainWindow::Update_score(int add_score)
{
    score+=add_score;
    qDebug()<<"当前分数为："<<score;
    ui->Score->display(score);
}

//关闭前的拦截操作
void MainWindow::closeEvent(QCloseEvent *event)
{
     QString str = QString::number(score);
    switch (Pass_Parameter) {
    case 0:
        QMessageBox::about(this, "死亡提示","恭喜你被击毙了，您的分数为："+str);
        break;
    case 1:
        QMessageBox::about(this, "通关提示","恭喜通关游戏，您的分数为："+str);

        break;
    default:
        break;
    }



}

