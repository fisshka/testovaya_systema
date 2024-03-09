#include "dialog.h"
#include "ui_dialog.h"
#include <QLineEdit>
#include "osnokno.h"



Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

}


Dialog::~Dialog()
{
    delete ui;
}

QString Dialog::text = "s";

void Dialog::on_buttonBox_accepted()
{
   Dialog::text = ui->lineEdit->text();
    qDebug()<<text;

    OsnOkno wn;
    wn.setModal(true);
    wn.exec();
    //this->close();

}

