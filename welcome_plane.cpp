#include "welcome_plane.h"
#include "ui_welcome_plane.h"

Welcome_Plane::Welcome_Plane(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Welcome_Plane)
{
    ui->setupUi(this);
}

Welcome_Plane::~Welcome_Plane()
{
    delete ui;
}

void Welcome_Plane::on_simple_Btn_clicked()
{
    MainWindow *w = new MainWindow(this,1,1,20,20);
    //设置窗口大小
    w->resize(1000,700);
    w->setFixedSize(1000,700);
    w->setObjectName("贪玩飞机");

    QPixmap pixmap;
    pixmap.load(":/picture/picture/bg1.jpg");
    QPalette  palette;
    palette.setBrush(w->backgroundRole(),QBrush(pixmap));
    w->setPalette(palette);
    w->setMask(pixmap.mask());  //可以将图片中透明部分显示为透明的
    w->setAutoFillBackground(true);
    w->show();
}



void Welcome_Plane::on_common_Btn_clicked()
{
    MainWindow *w = new MainWindow(this,3,2,20,20);
    //设置窗口大小
    w->resize(1000,700);
    w->setFixedSize(1000,700);
    w->setObjectName("贪玩飞机");

    QPixmap pixmap;
    pixmap.load(":/picture/picture/bg1.jpg");
    QPalette  palette;
    palette.setBrush(w->backgroundRole(),QBrush(pixmap));
    w->setPalette(palette);
    w->setMask(pixmap.mask());  //可以将图片中透明部分显示为透明的
    w->setAutoFillBackground(true);
    w->show();
}

void Welcome_Plane::on_difficult_Btn_clicked()
{
    MainWindow *w = new MainWindow(this,5,3,20,20);
    //设置窗口大小
    w->resize(1000,700);
    w->setFixedSize(1000,700);
    w->setObjectName("贪玩飞机");

    QPixmap pixmap;
    pixmap.load(":/picture/picture/bg1.jpg");
    QPalette  palette;
    palette.setBrush(w->backgroundRole(),QBrush(pixmap));
    w->setPalette(palette);
    w->setMask(pixmap.mask());  //可以将图片中透明部分显示为透明的
    w->setAutoFillBackground(true);
    w->show();
}

void Welcome_Plane::on_common_Btn_2_clicked()
{
//    if(ui->author1->text()=="陈刚"){
            if(ui->author1->text()=="王振科"){


    MainWindow *w = new MainWindow(this,10,1,100,150);
    //设置窗口大小
    w->resize(1000,700);
    w->setFixedSize(1000,700);
    w->setObjectName("贪玩飞机");

    QPixmap pixmap;
    pixmap.load(":/picture/picture/bg1.jpg");
    QPalette  palette;
    palette.setBrush(w->backgroundRole(),QBrush(pixmap));
    w->setPalette(palette);
    w->setMask(pixmap.mask());  //可以将图片中透明部分显示为透明的
    w->setAutoFillBackground(true);
    w->show();
     }
//}
}
