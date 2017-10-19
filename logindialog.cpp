#include "logindialog.h"
#include "ui_logindialog.h"
#include <QMessageBox>

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    QPixmap image; //定义一张图片
    image.load(":/myimages/resource/loginlogo.jpg");//加载
    ui->showlogo->clear();//清空
    ui->showlogo->setPixmap(image);//加载到Label标签
    ui->showlogo->setScaledContents(true);
    ui->showlogo->show();//显示
}

LoginDialog::~LoginDialog()
{
    delete ui;
}

void LoginDialog::on_exitBtn_clicked()
{
    //close();//close应该比exit好
    exit(0);
}

void LoginDialog::on_loginBtn_clicked()
{
    // 判断用户名和密码是否正确，
    // 如果错误则弹出警告对话框
    if(ui->comboBox->currentText() == tr("超级用户"))
    {
        if(ui->usrLineEdit->text().trimmed() == tr("lrk") &&
               ui->pwdLineEdit->text() == tr("xcf"))
        {
           emit sendLoginData(ui->usrLineEdit->text(),ui->comboBox->currentText());
           accept();
        }
        else
        {
        QMessageBox::warning(this, tr("警告！"),
                    tr("用户名或密码错误！"),
                    QMessageBox::Yes);
        // 清空内容并定位光标
        //ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->pwdLineEdit->setFocus();
        }
    }
    else
    {
    QMessageBox::warning(this, tr("警告！"),
                tr("该用户不属于此用户组"),
                QMessageBox::Yes);
    // 清空内容并定位光标
    ui->usrLineEdit->clear();
    ui->pwdLineEdit->clear();
    ui->usrLineEdit->setFocus();
    }
}
