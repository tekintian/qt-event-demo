#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    // 定时器事件
    virtual void timerEvent(QTimerEvent *e);


private:
    Ui::Widget *ui;
    // 定义2个定时器id 用于启动2个定时器
    int timerId1;
    int timerId2;

    int timerId3;
    int snum=5; // 定义用于倒计时的变量默认5
};
#endif // WIDGET_H
