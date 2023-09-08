#include "task.h"

TaskTableWidget::TaskTableWidget(QWidget *parent)
    : QTableWidget(parent)
{     
    setColumnCount(ColumnCount);
    QStringList headerLabels;
    headerLabels << "任务简称" << "起始时间" << "截止日期";
    setHorizontalHeaderLabels(headerLabels);
    taskVector = new QVector<Task>;
}

TaskTableWidget::~TaskTableWidget(){     
}


int TaskTableWidget::saveTask()
{
    // todo: 完成将 taskVector 中数据保存起来
    QFile file("workingTask.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);
        out << "order\t name\t prio\t state\t init_time\t start_time\t end_time\t task_tag\t description\n";

        for(auto item: *taskVector){
            out << item.order << "\t";
            out << item.name << "\t";
            out << item.prio << "\t";
            out << int(item.state) << "\t";
            out << item.init_time.toString("yyyy-MM-dd hh:mm:ss") << "\t";
            out << item.start_time.toString("yyyy-MM-dd hh:mm:ss") << "\t";
            out << item.end_time.toString("yyyy-MM-dd hh:mm:ss") << "\t";
            out << item.task_tag << "\t";
            out << item.description << "\t";
        }

        file.close();
    }else{
        return -1;
    }
    return 0;
}

int TaskTableWidget::loadTask()
{
    // todo: 完成将 taskVector 的数据读取出来
    QFile file("workingTask.txt");
    if (file.exists() && (file.open(QIODevice::ReadOnly | QIODevice::Text)))
    {
        QTextStream in(&file);

        // 逐行读取数据并添加到表格
        int row = 0;
        // ! 先消耗一行
        in.readLine();
        QDateTime currentTime = QDateTime::currentDateTime();
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList data = line.split("\t");
            Task *item = new Task();
            item->order = data[0].toULongLong();
            item->name = data[1];
            item->prio = data[2].toULongLong();
            item->state = TaskState(data[3].toUInt());
            item->init_time = QDateTime::fromString(data[4], "yyyy-MM-dd hh:mm:ss");
            item->start_time = QDateTime::fromString(data[5], "yyyy-MM-dd hh:mm:ss");
            item->end_time = QDateTime::fromString(data[6], "yyyy-MM-dd hh:mm:ss");
            item->task_tag = data[7];
            item->description = data[8];
            item->left_time = currentTime.secsTo(item->end_time);
            taskVector->push_back(*item);
        }

        file.close();
    }else{
        return -1;
    }
    return 0;
}

void TaskTableWidget::flushTable()
{

}

void TaskTableWidget::syncTable()
{
    
}


int TaskTableWidget::getSelectedRow()
{
    return selectedRow;
}

void TaskTableWidget::mousePressEvent(QMouseEvent *event)
{
    QTableWidgetItem *selectedItem = itemAt(event->pos());
    if (selectedItem) {
        selectedRow = selectedItem->row();
    } else {
        selectedRow = -1;
    }
    QTableWidget::mousePressEvent(event);
}