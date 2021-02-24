#ifndef MYLABEL_H
#define MYLABEL_H

#include <QLabel>

class MyLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyLabel(QWidget *parent = nullptr);
    //重写父类中的事件函数
    // 鼠标进入事件   alt+enter 实现定义
    virtual void enterEvent(QEvent *event);
    //鼠标离开事件//鼠标离开事件
    virtual void leaveEvent(QEvent *event);
    virtual void mousePressEvent(QMouseEvent *ev);
    virtual void mouseReleaseEvent(QMouseEvent *ev);
    virtual void mouseMoveEvent(QMouseEvent *ev);

    // 事件分发器 定义
    virtual bool event(QEvent *e);

signals:

};

#endif // MYLABEL_H
