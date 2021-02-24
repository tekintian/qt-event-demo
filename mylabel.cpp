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
 * 根据事件类型处理想要处理的事件后返回 bool ; 其他的事件在调用父类的事件分发器继续处理.
 * @brief MyLabel::event 重写父类的事件分发器
 * @param e 事件
 * @return
 */
bool MyLabel::event(QEvent *e)
{
    if(QEvent::MouseButtonPress  == e->type() )
    {
        qDebug()<<"我捕获了鼠标按下";

        // 由于 QEvent类中没有 x y 坐标信息, 而 QMouseEvent类中有xy坐标信息, 所以我们可以使用static_cast将 QEvent转换为 QMouseEvent
        QMouseEvent *ev = static_cast<QMouseEvent *>(e);
        qDebug("事件分发中鼠标按下的坐标 x=%d , y=%d ",ev->x(),ev->y() );

        return true; // 返回 true 表示本事件已经处理好了, 其他不会再处理; 如果这里不返回,则会返回父类中的事件处理会再次处理本事件
    }

    // 调用父类的event事件分发器处理其他事件  本类中的父类为QLavel,所以就调用的QLabel::event
    return QLabel::event(e);
}

/**
 * QObject中的 eventFilter 事件过滤器重写
 * 事件过滤返回 true 过滤成功 事件停止转发, false 过滤失败,事件继续转发
 * @brief MyLabel::eventFilter 事件过滤器
 * @param watched  事件发生的控件
 * @param event  具体的事件 如 时间 鼠标移动 按下等
 * @return
 */
bool MyLabel::eventFilter(QObject *watched, QEvent *event)
{
    // 先判断事件发生的控件
    if(this == watched) {
        if(QEvent::MouseButtonPress == event->type()) {
            qDebug()<<"事件过滤器中鼠标被单击了!";
            // 将QEvent转换为 QMouseEvent
            QMouseEvent *ev = static_cast<QMouseEvent *>(event);

            qDebug("过滤器中的鼠标坐标:x=%d, y=%d ", ev->x(), ev->y() );
        }
    }

    // 其他的交给父类的过滤器处理
    return QLabel::eventFilter(watched, event);



}
