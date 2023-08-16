#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

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
        int row = ui->tableWidget->rowCount();
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(name));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(gender));
    }
}