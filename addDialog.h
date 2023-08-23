#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QDateTime>
#include <QDateTimeEdit>
// #include <QComboBox>
#include <QPushButton>
#include <QVBoxLayout>

class AddInfoDialog : public QDialog
{
    Q_OBJECT

public:
    AddInfoDialog(QWidget *parent = nullptr)
        : QDialog(parent)
    {
        // 创建部件
        nameLabel = new QLabel("任务名称:", this);
        nameLineEdit = new QLineEdit(this);

        startLabel = new QLabel("起始时间:", this);
        startTimeEdit = new QDateTimeEdit(this);
        startTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
        startTimeEdit->setDateTime(QDateTime::fromMSecsSinceEpoch(0));

        endLabel = new QLabel("截止时间:", this);
        endTimeEdit = new QDateTimeEdit(this);
        endTimeEdit->setDisplayFormat("yyyy-MM-dd HH:mm:ss");
        endTimeEdit->setDateTime(QDateTime::fromMSecsSinceEpoch(0));

        confirmButton = new QPushButton("确认", this);
        cancelButton = new QPushButton("取消", this);

        // 连接按钮的点击事件到槽函数
        connect(confirmButton, &QPushButton::clicked, this, &AddInfoDialog::accept);
        connect(cancelButton, &QPushButton::clicked, this, &AddInfoDialog::reject);

        // 创建布局管理器
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(nameLabel);
        layout->addWidget(nameLineEdit);
        layout->addWidget(startLabel);
        layout->addWidget(startTimeEdit);
        layout->addWidget(endLabel);
        layout->addWidget(endTimeEdit);
        layout->addWidget(confirmButton);
        layout->addWidget(cancelButton);

        // 设置对话框布局
        setLayout(layout);

    }

    QString getName() const
    {
        return nameLineEdit->text();
    }

    QDateTime getStartTime() const
    {
        return startTimeEdit->dateTime();
    }

    QDateTime getEndTime() const
    {
        return endTimeEdit->dateTime();
    }


private:
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *startLabel;
    QDateTimeEdit *startTimeEdit;
    // QLineEdit *startLineEdit;
    QLabel *endLabel;
    QDateTimeEdit *endTimeEdit;
    // QLineEdit *endLineEdit;
    // QComboBox *genderComboBox;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
};


#endif