#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "logindialog.h"



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

void MainWindow::on_action_exit_triggered()
{
    close();
}
