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

class Task{
private:
    QString name;       // 任务名
    QDateTime start_time;
    QDateTime end_time;

public:
    Task(/* args */);
    ~Task();
};


const int ColumnCount = 3; // taskTable的列数


class TaskTableWiget : public QTableWidget
{
    Q_OBJECT

public:
    TaskTableWiget(QWidget *parent = nullptr)
        : QTableWidget(parent)
    {
        // setRowCount(5);
        setColumnCount(ColumnCount);

        // for (int row = 0; row < 5; ++row) {
        //     QTableWidgetItem *item1 = new QTableWidgetItem(QString("Item %1").arg(row));
        //     QTableWidgetItem *item2 = new QTableWidgetItem(QString("Value %1").arg(row * 10));
        //     setItem(row, 0, item1);
        //     setItem(row, 1, item2);
        // }
    }

protected:
    void mousePressEvent(QMouseEvent *event) override
    {
        QTableWidgetItem *selectedItem = itemAt(event->pos());
        if (selectedItem) {
            selectedRow = selectedItem->row();
        } else {
            selectedRow = -1;
        }
        QTableWidget::mousePressEvent(event);
    }

private:
    int selectedRow = -1;
};







#endif