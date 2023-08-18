#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
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
        startLineEdit = new QLineEdit(this);
        startLineEdit->setText("2023-7-7");

        endLabel = new QLabel("截止时间:", this);
        endLineEdit = new QLineEdit(this);

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
        layout->addWidget(startLineEdit);
        layout->addWidget(endLabel);
        layout->addWidget(endLineEdit);
        layout->addWidget(confirmButton);
        layout->addWidget(cancelButton);

        // 设置对话框布局
        setLayout(layout);
    }

    QString getName() const
    {
        return nameLineEdit->text();
    }

    QString getStartTime() const
    {
        return startLineEdit->text();
    }

    QString getEndTime() const
    {
        return endLineEdit->text();
    }


private:
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *startLabel;
    QLineEdit *startLineEdit;
    QLabel *endLabel;
    QLineEdit *endLineEdit;
    // QComboBox *genderComboBox;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
};


#endif