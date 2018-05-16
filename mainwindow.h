#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qslider.h>
#include"person.h"
#include"house.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    void paintEvent(QPaintEvent *);
    void setperson(person p);
    void sethouse(house h);
    ~MainWindow();
protected slots:
    void changesize(int a);
    void changesize2(int a);
    void action();
private slots:

    void on_spinBox_valueChanged(int arg1);

private:
    Ui::MainWindow *ui;
    void keyPressEvent(QKeyEvent *push);
    QTimer *time;
    QSlider *pSlider,*pSlider2;
    int size=10;
    int states=0;
    double angles=0;
    bool if_up=true;
    bool if_turn=true;
    int getsize=0,getsize2=0;
    person man;
    house home;
};

#endif // MAINWINDOW_H
