#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include <QMessageBox>
#include "xml.h"
#include "typechange.h"

namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog
{
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = 0);
    ~LoginDialog();

private slots:
    void on_exitBtn_clicked();
    void on_loginBtn_clicked();

private:
    Ui::LoginDialog *ui;

signals:
    void sendLoginData(QString,QString);

};

#endif // LOGINDIALOG_H
