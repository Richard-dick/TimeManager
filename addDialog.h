#ifndef ADDDIALOG_H
#define ADDDIALOG_H

#include <QDialog>
#include <QLabel>
#include <QLineEdit>
#include <QComboBox>
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
        nameLabel = new QLabel("名字:", this);
        nameLineEdit = new QLineEdit(this);
        genderLabel = new QLabel("性别:", this);
        genderComboBox = new QComboBox(this);
        genderComboBox->addItem("男");
        genderComboBox->addItem("女");
        confirmButton = new QPushButton("确认", this);
        cancelButton = new QPushButton("取消", this);

        // 连接按钮的点击事件到槽函数
        connect(confirmButton, &QPushButton::clicked, this, &AddInfoDialog::accept);
        connect(cancelButton, &QPushButton::clicked, this, &AddInfoDialog::reject);

        // 创建布局管理器
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(nameLabel);
        layout->addWidget(nameLineEdit);
        layout->addWidget(genderLabel);
        layout->addWidget(genderComboBox);
        layout->addWidget(confirmButton);
        layout->addWidget(cancelButton);

        // 设置对话框布局
        setLayout(layout);
    }

    QString getName() const
    {
        return nameLineEdit->text();
    }

    QString getGender() const
    {
        return genderComboBox->currentText();
    }

private:
    QLabel *nameLabel;
    QLineEdit *nameLineEdit;
    QLabel *genderLabel;
    QComboBox *genderComboBox;
    QPushButton *confirmButton;
    QPushButton *cancelButton;
};


#endif