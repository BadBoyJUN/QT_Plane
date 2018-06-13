#ifndef WELCOME_PLANE_H
#define WELCOME_PLANE_H
#include "mainwindow_dlgs.h"
#include <QPixmap>
#include <QPalette>
#include <QBitmap>

#include <QWidget>

namespace Ui {
class Welcome_Plane;
}

class Welcome_Plane : public QWidget
{
    Q_OBJECT

public:
    explicit Welcome_Plane(QWidget *parent = 0);
    ~Welcome_Plane();

private slots:
    void on_simple_Btn_clicked();

    void on_difficult_Btn_clicked();

    void on_common_Btn_clicked();

    void on_common_Btn_2_clicked();

private:
    Ui::Welcome_Plane *ui;
};

#endif // WELCOME_PLANE_H
