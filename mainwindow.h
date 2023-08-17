#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QTableWidgetItem>
#include <QDateTime>
#include <QTimer>

#include "addDialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

const int ColumnCount = 3; // missionXXTable的列数

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QDateTime currentTime;
    // QTableWidget *tableWidget; // 声明一个成员变量以便在槽函数中使用


private slots:
    void add_mission();
    void timerUpdate();
};
#endif // MAINWINDOW_H
