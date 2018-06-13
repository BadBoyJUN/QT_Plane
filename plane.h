#ifndef PLANE_H
#define PLANE_H
#include <QPixmap>
#include <QPainter>
#include <QWidget>
#include <QPaintEvent>
#include <QPointF>
#include <QDebug>
#include <QList>
#include <iterator>
#include <QTime>
#include <QPixmap>
#include <QMediaPlayer>
#include <QObject>
#include <QMessageBox>

/**
 * @brief The plane class
 * 所有的抽象类
 */
class plane : public QObject
{
    Q_OBJECT

public:
    plane();
    //构造函数：父级要draw的窗口对象，坐标和大小
    explicit plane(QWidget *widget, int x ,int y , int width , int height , int distance);

    //移动飞机
    virtual void To_move(int direction)=0;
    //画飞机
    virtual void draw()=0;
    //加载图片
    void LoadingPicture(QString pixpath);

    //飞机坠毁,以及特效显示
    virtual void drop();
    //判断该飞机 是否坠毁
    virtual bool isdrop();

public:
    //图片
    QPixmap picture ;
    //坐标
    int x;
    int y;
    //宽高大小
    int width;
    int height;
    //显示窗口
    QWidget * parent;
    //移动距离
    int distance;
    //true为可以被碰撞
    bool is_drop = true;


private:


};

#endif // PLANE_H
