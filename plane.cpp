#include "plane.h"
#include <QKeyEvent>

plane::plane()
{

}

plane::plane(QWidget *widget, int x, int y, int width, int height, int distance): QObject(widget)
{
    this->parent = widget;
    this->x=x;
    this->y=y;
    this->width = width;
    this->height = height;
    this->distance = distance;
}


void plane::LoadingPicture(QString pixpath)
{
    this->picture.load(pixpath);
}

void plane::drop()
{

}

bool plane::isdrop()
{
    if(is_drop){
        return true;
    }
    return false;
}

