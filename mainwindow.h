#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

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
    void on_pushButton_clicked();
};


#endif // MAINWINDOW_H
