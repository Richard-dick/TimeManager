#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // ! 时间显示
    timerUpdate();
    debugInfo("Setting up time display!");
    QTimer *timer = new QTimer(this);
    timer->start(1000);

    // ! 初始化 任务 Table
    // 设置列标题
    debugInfo("Init task Table !");
    ui->taskWorkingTable->setColumnCount(ColumnCount);
    QStringList headerLabels;
    headerLabels << "任务简称" << "起始时间" << "截止日期";
    ui->taskWorkingTable->setHorizontalHeaderLabels(headerLabels);
    // 同步数据
    loadTaskData();

    // ! 添加槽函数
    connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate())); // 时间更新
    connect(ui->addButton, &QPushButton::clicked, this, &MainWindow::add_task); // 添加任务的会话
    connect(ui->saveTaskButton, &QPushButton::clicked, this, &MainWindow::saveTaskData); // 保存任务的会话
    connect(this, &MainWindow::closeEvent, this, &MainWindow::saveBeforeClose); // 连接窗口关闭事件到槽函数
    
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::add_task()
{
    // 创建对话框实例
    debugInfo("To add task !");
    AddInfoDialog dialog(this);
    if (dialog.exec() == QDialog::Accepted)
    {
        // 获取对话框中的信息
        QString name = dialog.getName();
        QDateTime start = dialog.getStartTime();
        QDateTime end = dialog.getEndTime();

        // 将信息添加到表格
        int row = ui->taskWorkingTable->rowCount();
        ui->taskWorkingTable->insertRow(row);
        ui->taskWorkingTable->setItem(row, 0, new QTableWidgetItem(name));
        ui->taskWorkingTable->setItem(row, 1, new QTableWidgetItem(start.toString("yyyy-MM-dd")));
        ui->taskWorkingTable->setItem(row, 2, new QTableWidgetItem(end.toString("yyyy-MM-dd")));
    }
    debugInfo("Task added successfully");
}

// 定义成员函数timerUpdate()实现用户界面显示时间：
void MainWindow::timerUpdate()
{
    currentTime = QDateTime::currentDateTime();

    QString str = currentTime.toString("yyyy-MM-dd \ndddd \nhh:mm:ss ");

    ui->datetimeLabel->setText(str);
}

void MainWindow::saveTaskData()
{
    QFile file("workingTask.txt");
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream out(&file);

        // 保存每行的数据
        for (int row = 0; row < ui->taskWorkingTable->rowCount(); ++row)
        {
            for (int col = 0; col < ui->taskWorkingTable->columnCount(); ++col)
            {
                QTableWidgetItem *item = ui->taskWorkingTable->item(row, col);
                if (item)
                {
                    out << item->text();
                }
                if (col < ui->taskWorkingTable->columnCount() - 1)
                {
                    out << "\t"; // 使用制表符分隔列
                }
            }
            out << "\n"; // 换行分隔行
        }

        file.close();
        debugInfo("Successfully save!!");
    }else{
        debugInfo("Failed to save!!");
    }
}

void MainWindow::loadTaskData()
{
    QFile file("workingTask.txt");
    if (file.exists() && (file.open(QIODevice::ReadOnly | QIODevice::Text)))
    {
        QTextStream in(&file);

        // 逐行读取数据并添加到表格
        int row = 0;
        // ui->debugEdit->setText(QString::number(row));
        while (!in.atEnd())
        {
            QString line = in.readLine();
            QStringList data = line.split("\t");
            ui->taskWorkingTable->insertRow(row);
            for (int col = 0; col < data.size(); ++col)
            {
                QTableWidgetItem *item = new QTableWidgetItem(data[col]);
                ui->taskWorkingTable->setItem(row, col, item);
            }
            ++row;
        }

        file.close();
    }else{
        debugInfo("No such file");
    }
}

void MainWindow::saveBeforeClose(QCloseEvent *event)
{
    // 在关闭前保存表格数据
    saveTaskData();

    // 继续执行窗口关闭操作
    event->accept();
}


void MainWindow::debugInfo(const QString &text)
{
    QString currentText = ui->debugEdit->toPlainText(); // 获取当前文本

    if (!currentText.isEmpty())
    {
        currentText += "\n"; // 添加换行符，将新内容追加到新行
    }

    QString formattedDateTime = currentTime.toString("yyyy-MM-dd HH:mm:ss"); // 格式化时间

    QString fullText = "[" + formattedDateTime + "] " + text; // 将时间和文本拼接

    currentText += fullText; // 将新文本追加到当前文本

    ui->debugEdit->setText(currentText); // 设置新的文本
}