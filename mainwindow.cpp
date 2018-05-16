#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"point.h"
#include"line.h"
#include"person.h"
#include"house.h"
#include <QTime>
#include<QKeyEvent>
#include <QPainter>
#include <stdio.h>
#include <windows.h>
#include <QMessageBox>
#include <string.h>
#include <QtCore>
#include<QDebug>
#include <QWidget>
#include <QtGui>
#include <qslider.h>
#include<QSpinBox>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("人物和房屋");
    pSlider = new QSlider(this);
    pSlider->setOrientation(Qt::Horizontal);
    pSlider->setMinimum(1);
    pSlider->setMaximum(20);
    pSlider->setSingleStep(1);
    connect(pSlider, SIGNAL(valueChanged(int)), this, SLOT(changesize(int)));
    pSlider->setValue(10);
    pSlider->setGeometry(rect().x()+50, rect().y()+10,350, 20);
    pSlider->setParent(this);

    pSlider2 = new QSlider(this);
    pSlider2->setOrientation(Qt::Horizontal);
    pSlider2->setMinimum(1);
    pSlider2->setMaximum(20);
    pSlider2->setSingleStep(1);
    connect(pSlider2, SIGNAL(valueChanged(int)), this, SLOT(changesize2(int)));
    pSlider2->setValue(15);
    pSlider2->setGeometry(rect().x()+50, rect().y()+35,350, 20);
    pSlider2->setParent(this);
    time = new QTimer(this);
    connect(time,SIGNAL(timeout()),this,SLOT(action()));
    time->start(20);
}
void MainWindow::setperson(person p){
    this->man=p;
}
void MainWindow::sethouse(house h){
    this->home=h;
}
int px=100,py=100,hx=200,hy=150;
void MainWindow::changesize(int a){
    person man(px,py,a,this->states,angles);
    this->getsize=a;
    this->setperson(man);
    this->repaint();
}
void MainWindow::changesize2(int a2){
    house home(hx,hy,a2);
    this->getsize2=a2;
    this->sethouse(home);
    this->repaint();
}
void MainWindow::keyPressEvent(QKeyEvent *push){
    if(push->key()==Qt::Key_A)px-=10;
    if(push->key()==Qt::Key_D)px+=10;
    if(push->key()==Qt::Key_W)py-=10;
    if(push->key()==Qt::Key_S)py+=10;
    if(push->key()==Qt::Key_J)hx-=10;
    if(push->key()==Qt::Key_L)hx+=10;
    if(push->key()==Qt::Key_I)hy-=10;
    if(push->key()==Qt::Key_K)hy+=10;
    person man(px,py,getsize,this->states,angles);
    house home(hx,hy,getsize2);
    this->setperson(man);
    this->sethouse(home);
    this->repaint();
}
void MainWindow::action(){
    if(if_up==true)
    this->states++;
    else this->states--;
    if(this->states>=this->getsize){
        if_up=false;
    }
    if(this->states<=0){
        if_up=true;
    }
    if(if_turn==true)
    this->angles+=1.5707963/this->getsize;
    else this->angles-=1.5707963/this->getsize;
    if(this->angles>=3.1415926/2)
        if_turn=false;
    if(this->angles<=0)
        if_turn=true;
    person man(px,py,getsize,this->states,angles);
    house home(hx,hy,getsize2);
    this->setperson(man);
    this->sethouse(home);
    this->repaint();
}
int h=0;
void MainWindow::paintEvent(QPaintEvent *){
    QPainter paint(this);
    paint.drawPixmap(rect(), QPixmap("://11-1501300UP0J8.jpg"));
    paint.setPen(QPen(Qt::blue,2));
    this->home.drawhouse(paint);
    paint.setPen(QPen(Qt::red,2));
    this->man.drawperson(paint);
}
MainWindow::~MainWindow()
{
    delete ui;
    delete time;
    delete pSlider;
    delete pSlider2;
}

void MainWindow::on_spinBox_valueChanged(int arg1)
{
    house home(hx,hy,arg1);
    this->getsize2=arg1;
    this->sethouse(home);
    this->repaint();
}
