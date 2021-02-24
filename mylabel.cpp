#include "mylabel.h"
#include<QMouseEvent>

#include<QDebug>

MyLabel::MyLabel(QWidget *parent) : QLabel(parent)
{
    // 设置鼠标跟踪功能, 用户不需要按下鼠标按键即可获取鼠标当前坐标
    this->setMouseTracking(true);
}

void MyLabel::enterEvent(QEvent *event)
{
    qDebug()<<"鼠标进入了" << endl;
}

void MyLabel::leaveEvent(QEvent *event)
{
    qDebug()<<"鼠标离开了" << endl;
}

void MyLabel::mousePressEvent(QMouseEvent *ev)
{
    qDebug()<<"鼠标按下了";

    // 判断鼠标的按键
    if(ev->button()==Qt::LeftButton){
        qDebug()<<"你按下了左键: x="<<ev->x() << " y="<<ev->y();
    }
    else if(ev->button()==Qt::RightButton){
        qDebug()<<"你按下了右键: x="<<ev->x() << " y="<<ev->y();
    }

}

void MyLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    qDebug()<<"鼠标释放了";
}

void MyLabel::mouseMoveEvent(QMouseEvent *ev)
{
    // 需要在构造函数中开启鼠标跟踪功能this->setMouseTracking(true); 这里才能获取坐标
    qDebug()<<"鼠标移动: x="<<ev->x() << " y="<<ev->y();

}

/**
 * 父类的事件分发器重写实现
 * 根据事件类型处理想要处理的事件后返回true; 其他的事件在调用父类的事件分发器继续处理.
 * @brief MyLabel::event 重写父类的事件分发器
 * @param e 事件
 * @return
 */
bool MyLabel::event(QEvent *e)
{
    if(QEvent::MouseButtonPress  == e->type() )
    {
        qDebug()<<"我捕获了鼠标按下"<<endl;
        return true; // 返回 true 表示本事件已经处理好了, 其他不会再处理; 如果不返回true则父类中的事件处理会再次处理本事件
    }

    // 调用父类的event事件分发器处理其他事件  本类中的父类为QLavel,所以就调用的QLabel::event
    return QLabel::event(e);
}
