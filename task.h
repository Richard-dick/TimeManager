#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDateTime>

class task
{
private:
    QString name;       // 任务名
    QDateTime start_time;
    QDateTime end_time;




public:
    task(/* args */);
    ~task();
};










#endif