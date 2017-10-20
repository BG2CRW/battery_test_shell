#include "logindialog.h"
#include "ui_logindialog.h"

Camera_config battery_conf;
XmlContainer configXml;

LoginDialog::LoginDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    //显示logo
    QPixmap image; //定义一张图片
    image.load(":/myimages/resource/loginlogo.jpg");//加载
    ui->showlogo->clear();//清空
    ui->showlogo->setPixmap(image);//加载到Label标签
    ui->showlogo->setScaledContents(true);
    ui->showlogo->show();//显示
    //读取xml
    configXml.readXml(&battery_conf);
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
    QString usrName = QString::fromStdString(battery_conf.usrName);
    QString usrPassword = QString::fromStdString(battery_conf.usrPassword);
    QString managerName = QString::fromStdString(battery_conf.managerName);
    QString managerPassword = QString::fromStdString(battery_conf.managerPassword);
    // 判断用户名和密码是否正确，
    // 如果错误则弹出警告对话框
    if(ui->comboBox->currentText() == tr("管理员"))//选择管理员
    {
        if(ui->usrLineEdit->text().trimmed() == managerName &&
               ui->pwdLineEdit->text() == managerPassword)
        {
           emit sendLoginData(ui->usrLineEdit->text(),ui->comboBox->currentText());
           accept();
        }
        else
        {
        QMessageBox::warning(this, tr("警告！"),
                    tr("该管理员用户名或密码错误！"),
                    QMessageBox::Yes);
        // 清空内容并定位光标
        //ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->pwdLineEdit->setFocus();
        }
    }
    else//选择操作员
    {
        if(ui->usrLineEdit->text().trimmed() == usrName &&
               ui->pwdLineEdit->text() == usrPassword)
        {
           emit sendLoginData(ui->usrLineEdit->text(),ui->comboBox->currentText());
           accept();
        }
        else
        {
        QMessageBox::warning(this, tr("警告！"),
                    tr("该操作员用户名或密码错误！"),
                    QMessageBox::Yes);
        // 清空内容并定位光标
        //ui->usrLineEdit->clear();
        ui->pwdLineEdit->clear();
        ui->pwdLineEdit->setFocus();
        }
    }
}
