#include "osnokno.h"
#include "ui_osnokno.h"
#include <QCheckBox>
#include <QLabel>
#include <QString>
#include <QDebug>
#include "dialog.h"




void OsnOkno::vivod()
{QString s, temp;
temp = stream.readLine();
while(!temp.trimmed().isEmpty())
{
    s += temp;
    s += '\n';
    temp = stream.readLine();
    if (stream.atEnd())
       break;

}

ui->label->setText((s));
}



OsnOkno::OsnOkno(QWidget *parent) : QDialog(parent),
    ui(new Ui::OsnOkno)
{
    ui->setupUi(this);
    t.setFileName("C:\\Games\\untitled3\\resorc\\test.txt");
    t.open(QIODevice::ReadOnly);
    stream.setDevice(&t);
    if(!t.isOpen())
       ui->label->setText("привет");
    ui->label->setTextFormat(Qt::PlainText);
    ui->label->setFont(QFont("Arial", 8));
    vivod();






}

OsnOkno::~OsnOkno()
{
    delete ui;
}

void OsnOkno::on_pushButton_clicked()
{

    int tmp;
    if(ui->checkBox->isChecked())
        tmp = 1;
    if(ui->checkBox_2->isChecked())
        tmp = 2;
    if(ui->checkBox_3->isChecked())
        tmp = 3;
    if(ui->checkBox_4->isChecked())
        tmp = 4;
    QString x;
    x = stream.readLine();
    if(tmp == x.toInt())
    {    marks++;

    }
    ui->checkBox->setCheckState(Qt::Unchecked);
    ui->checkBox_2->setCheckState(Qt::Unchecked);
    ui->checkBox_3->setCheckState(Qt::Unchecked);
    ui->checkBox_4->setCheckState(Qt::Unchecked);
    vivod();
    if (stream.atEnd())
    {
        x = "Вы успешно завершили тест! Выш результат " + QString::number(marks) + " баллов из 5";
        ui->label->setText(x);
        ui->checkBox_4->hide();
        ui->checkBox_3->hide();
        ui->checkBox_2->hide();
        ui->checkBox->hide();
        ui->pushButton->hide();

    }


}

void OsnOkno::on_pushButton_2_clicked()
{
    QCoreApplication::quit();
    t.close();
    if(!Dialog::text.isEmpty())
    {
    QString filename = "C:\\Games\\untitled3\\resorc\\"+ Dialog::text +".txt";
    t.setFileName(filename);
    if (!t.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "ERROR:" << t.errorString();

        }
    stream.setDevice(&t);
    stream << "Result: " + QString::number(marks) + "\n";
    t.close();}
    qDebug()<<Dialog::text;


}
