#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidgetItem>
#include <QDateTime>
#include <QTimer>

#include <QFile>
#include <QTextStream>

#include <QCloseEvent>
// #include <QString>

#include "addDialog.h"
#include "task.h"
#include "utils.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void saveTaskData();
    void loadTaskData();
    void debugInfo(const QString &text);

private:
    Ui::MainWindow *ui;
    QDateTime currentTime;
    TaskTableWidget *taskWorkingTable;
    // QTableWidget *tableWidget; // 声明一个成员变量以便在槽函数中使用


private slots:
    void add_task();
    void del_task();
    void timerUpdate();
    void saveBeforeClose(QCloseEvent *event);
};
#endif // MAINWINDOW_H


