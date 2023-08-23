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
    void saveMissionData();
    void loadMissionData();
    void debugInfo(const QString &text);

private:
    Ui::MainWindow *ui;
    QDateTime currentTime;
    // QTableWidget *tableWidget; // 声明一个成员变量以便在槽函数中使用


private slots:
    void add_mission();
    void timerUpdate();
    void saveBeforeClose(QCloseEvent *event);
};
#endif // MAINWINDOW_H


