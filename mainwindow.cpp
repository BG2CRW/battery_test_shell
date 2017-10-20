#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receiveLoginData(QString usrName,QString usrType)
{
    ui->label_3->setText(usrName);
    ui->label_4->setText(usrType);
    if(usrType == tr("操作员"))
    {
        ui->action_usrSet->setEnabled(false);
    }
}

int MainWindow::loginCall()
{
    //信号槽方式下父子窗体传值的测试
    LoginDialog *dlg = new LoginDialog;
    //关联信号和槽函数
    connect(dlg,SIGNAL(sendLoginData(QString,QString)),this,SLOT(receiveLoginData(QString,QString)));
    // dlg->setModal(true); 不论是模态或者非模态都可以正常传值
    dlg->show();
    if(dlg->exec() == QDialog::Accepted)
    {
        return 1;
    }
    else
        return 2;
}

void MainWindow::on_action_exit_triggered()//退出功能
{
    close();
}

void MainWindow::on_action_logout_triggered()//注销功能
{
    //方法1：
    qApp->quit();
    QProcess::startDetached(qApp->applicationFilePath(), QStringList());
    //方法2：
    //qApp->exit(888);
}

void MainWindow::on_action_usrSet_triggered()//用户设置功能
{
    Usrset *usrset = new Usrset;
    usrset->setModal(true);
    usrset->show();
}
