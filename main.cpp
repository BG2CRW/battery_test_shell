#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    int logout_number = 0;

    do{
        QApplication a(argc, argv);
        MainWindow w;
        if(w.loginCall()==1)
        {
            w.show();
            logout_number = a.exec();
        }
    }
    while(logout_number == 888);

    return logout_number;
}
