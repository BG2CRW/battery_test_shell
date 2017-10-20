#include "usrset.h"
#include "ui_usrset.h"

extern Camera_config battery_conf;
XmlContainer configXml0;

Usrset::Usrset(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Usrset)
{
    ui->setupUi(this);
}

Usrset::~Usrset()
{
    delete ui;
}

void Usrset::on_pushButton_usr_clicked()
{
    QString usrName = QString::fromStdString(battery_conf.usrName);
    QString usrPassword = QString::fromStdString(battery_conf.usrPassword);
    QString managerName = QString::fromStdString(battery_conf.managerName);
    QString managerPassword = QString::fromStdString(battery_conf.managerPassword);
    usrName = ui->usr_name->text();
    usrPassword = ui->usr_password->text();
    battery_conf.usrName = usrName.toStdString();
    battery_conf.usrPassword = usrPassword.toStdString();
    battery_conf.managerName = managerName.toStdString();
    battery_conf.managerPassword = managerPassword.toStdString();
    configXml0.writeXml(&battery_conf);//写入
    //改完后提示
    QMessageBox::warning(this, tr("提示！"),
                tr("操作员用户名和密码已修改成功！"),
                QMessageBox::Yes);
    ui->usr_password->clear();
}

void Usrset::on_pushButton_manager_clicked()
{
    QString usrName = QString::fromStdString(battery_conf.usrName);
    QString usrPassword = QString::fromStdString(battery_conf.usrPassword);
    QString managerName = QString::fromStdString(battery_conf.managerName);
    QString managerPassword = QString::fromStdString(battery_conf.managerPassword);
    if( ui->manager_password_old->text().trimmed() == managerPassword )
    {
        if( ui->manager_password_new->text().trimmed() == ui->manager_password_confirm->text().trimmed() )
        {
            managerName = ui->manager_name->text();
            managerPassword = ui->manager_password_confirm->text();
            battery_conf.usrName = usrName.toStdString();
            battery_conf.usrPassword = usrPassword.toStdString();
            battery_conf.managerName = managerName.toStdString();
            battery_conf.managerPassword = managerPassword.toStdString();
            configXml0.writeXml(&battery_conf);//写入
            //改完后提示
            QMessageBox::warning(this, tr("提示！"),
                        tr("管理员用户名和密码已修改成功！请重新登录！请牢记新用户名与密码！！"),
                        QMessageBox::Yes);
            //注销重新登录
            qApp->quit();
            QProcess::startDetached(qApp->applicationFilePath(), QStringList());
        }
        else
        {
            QMessageBox::warning(this, tr("错误！"),
                        tr("两次密码输入不一致！请重新输入！"),
                        QMessageBox::Yes);
            ui->manager_password_old->clear();
            ui->manager_password_new->clear();
            ui->manager_password_confirm->clear();
        }
    }
    else
    {
        QMessageBox::warning(this, tr("错误！"),
                    tr("原密码输入错误，请重试！"),
                    QMessageBox::Yes);
        ui->manager_password_old->clear();
        ui->manager_password_new->clear();
        ui->manager_password_confirm->clear();
    }

}
