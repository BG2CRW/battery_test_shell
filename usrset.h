#ifndef USRSET_H
#define USRSET_H

#include <QDialog>
#include <QMessageBox>
#include <QProcess>
#include "xml.h"
#include "typechange.h"

namespace Ui {
class Usrset;
}

class Usrset : public QDialog
{
    Q_OBJECT

public:
    explicit Usrset(QWidget *parent = 0);
    ~Usrset();

private slots:
    void on_pushButton_usr_clicked();
    void on_pushButton_manager_clicked();

private:
    Ui::Usrset *ui;
};

#endif // USRSET_H
