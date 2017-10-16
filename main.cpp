#include "mainwindow.h"
#include <QApplication>
#include "logindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;

    while(1)
    {
        if(w.loginCall()==1)
        {
            w.show();
            return a.exec();
        }
    }

}
