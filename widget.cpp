#include "widget.h"
#include "ui_widget.h"
#include <QTimer>
#include <QTimerEvent>
#include<QPushButton>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //启动定时器事件 1个定时器
   // this->startTimer(1000); // 单位是毫秒

    this->timerId1 = this->startTimer(1000); // 1秒启动1此

    this->timerId2 = this->startTimer(100); // 100毫秒启动一次

    this->timerId3 = this->startTimer(1000);

    // 对象定时start

    // 定时器对象启动定时器
    //创建一个定时器对象
    QTimer *timer = new QTimer(this);
    // timer对象通过绑定timeout信号来实现时间设置
    connect(timer,&QTimer::timeout,[=](){
        static int num = 0;
        ui->label_timer->setText(QString::number(++num));
    });

    connect(ui->pushButton_timer_start,&QPushButton::clicked,[=](){
        timer->start(1000);// 1000毫秒启动一次
    });
    connect(ui->pushButton_timer_stop, &QPushButton::clicked,[=](){
        timer->stop();
    });
    // 对象定时end

    // 使用singleShot实现延时功能
   // [static] void QTimer::singleShot(std::chrono::milliseconds msec, const QObject *receiver, const char *member)
    QTimer::singleShot(6000,[=](){
        ui->label_singleShot->setText("恭喜,你中奖了!");
    });


}

Widget::~Widget()
{
    delete ui;
}
/**
 * 定时器事件实现
 * @brief Widget::timerEvent
 * @param e
 */
void Widget::timerEvent(QTimerEvent *e)
{
   // static int time =0,num1=0,num2=2;
   // ui->label_timer1->setText(QString::number(time++));

    static int num1=0,num2=2;
    // 多个定时器的情况,必须通过 timerId() 判断是那个定时器触发
    if(timerId1 == e->timerId() ) {
        ui->label_timer1->setText(QString::number(num1++));

    }else if (timerId2 == e->timerId() ) {
        ui->label_timer2->setText(QString::number(num2++));
    }else if(timerId3 == e->timerId() ){
        // 倒计时显示 5秒后显示结果:
        if(snum>0){
            ui->label_count_down_show->setText("等待 "+QString::number(snum--)+" 秒后显示中奖结果");
        }else{
            this->killTimer(timerId3); // 结束时间定时器
            ui->label_count_down_show->setText("恭喜你,中 一等奖 !");
        }
    }


}

