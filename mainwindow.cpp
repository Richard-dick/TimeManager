#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ! 时间显示
    timerUpdate();
    QTimer *timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));
    timer->start(1000);

    // ! 初始化 任务 Table
    // 设置列标题
    ui->missionWorkingTable->setColumnCount(ColumnCount);
    QStringList headerLabels;
    headerLabels << "任务简称" << "起始时间" << "截止日期";
    ui->missionWorkingTable->setHorizontalHeaderLabels(headerLabels);

    // 添加示例数据，这只是一个简化的示例
    // ui->missionWorkingTable->insertRow(0);
    // ui->missionWorkingTable->setItem(0, 0, new QTableWidgetItem("任务1"));
    // ui->missionWorkingTable->setItem(0, 1, new QTableWidgetItem("2023-08-15"));
    // ui->missionWorkingTable->setItem(0, 2, new QTableWidgetItem("2023-08-20"));

    // ! 添加槽函数
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::add_mission);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::add_mission()
{
    // 创建对话框实例
    AddInfoDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        // 获取对话框中的信息
        QString name = dialog.getName();
        QString gender = dialog.getGender();

        // 将信息添加到表格
        int row = ui->missionWorkingTable->rowCount();
        ui->missionWorkingTable->insertRow(row);
        ui->missionWorkingTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->missionWorkingTable->setItem(row, 1, new QTableWidgetItem(gender));
    }
}

// 定义成员函数timerUpdate()实现用户界面显示时间：
void MainWindow::timerUpdate()
{
    currentTime = QDateTime::currentDateTime();

    QString str = currentTime.toString("yyyy-MM-dd \ndddd \nhh:mm:ss ");

    ui->datetimeLabel->setText(str);
}