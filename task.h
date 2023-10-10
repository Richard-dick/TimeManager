#ifndef TASK_H
#define TASK_H

#include <QString>
#include <QDateTime>
#include <QApplication>
#include <QWidget>
#include <QTableWidget>
#include <QToolBar>
#include <QAction>
#include <QVBoxLayout>
#include <QMouseEvent>

#include <QFile>
#include <QTextStream>

#include <QVector>

enum TaskState {
    TODO,
    DOING,
    DONE,
    INTR,
    ABANDON
};



typedef struct task{
    // uint64_t order;
    // uint64_t prio;
    // TaskState state;
    uint64_t left_time;
    // QDateTime init_time;
    QDateTime start_time;
    QDateTime end_time;
    QString name;
    // QString description;
    // QString task_tag;
}Task;


const int ColumnCount = 4; // taskTable的列数


class TaskTableWidget : public QTableWidget
{
    Q_OBJECT

public:
    TaskTableWidget(QWidget *parent = nullptr);
    ~TaskTableWidget();
    int getSelectedRow();
    int saveTask();
    int loadTask();
    void flushTable();
    void syncTable();
    int addTask(Task &);
    int deleteTask();


protected:
    void mousePressEvent(QMouseEvent *event) override;

private:
    int selectedRow = -1;
    QVector<Task> *taskVector;
};







#endif