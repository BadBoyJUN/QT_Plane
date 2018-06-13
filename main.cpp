#include "mainwindow_dlgs.h"
#include <QApplication>
#include <QPixmap>
#include <QPalette>
#include <QBitmap>
#include "welcome_plane.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Welcome_Plane w;
    //设置窗口大小
    w.resize(590,450);
    w.setFixedSize(590,450);
    w.setObjectName("贪玩飞机");

//w.setStyleSheet("QFrame#myframe{border-image:url(:/picture/picture/Plane_background.jpg)}" );
    QPixmap pixmap;
    pixmap.load(":/picture/picture/welcome.jpg");
    QPalette  palette;
    palette.setBrush(w.backgroundRole(),QBrush(pixmap));
    w.setPalette(palette);
    w.setMask(pixmap.mask());  //可以将图片中透明部分显示为透明的
    w.setAutoFillBackground(true);
    w.show();



    return a.exec();
}
