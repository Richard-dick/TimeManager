#include "task.h"

TaskTableWidget::TaskTableWidget(QWidget *parent)
    : QTableWidget(parent)
{     
    setColumnCount(ColumnCount);
    QStringList headerLabels;
    headerLabels << "任务简称" << "起始时间" << "截止日期";
    setHorizontalHeaderLabels(headerLabels);
    taskVector = new std::vector<Task>;
};

TaskTableWidget::~TaskTableWidget(){     
};

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