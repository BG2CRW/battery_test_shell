#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include "logindialog.h"
#include "xml.h"
#include "typechange.h"
#include "usrset.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    int loginCall();
    ~MainWindow();

private:
    Ui::MainWindow *ui;

public slots:
    void receiveLoginData(QString usrName,QString usrType);
private slots:
    void on_action_exit_triggered();
    void on_action_logout_triggered();
    void on_action_usrSet_triggered();
};


#endif // MAINWINDOW_H
