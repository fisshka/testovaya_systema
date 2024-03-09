#ifndef OSNOKNO_H
#define OSNOKNO_H

#include <QDialog>
#include <dialog.h>
#include <QFile>
#include <QTextStream>

namespace Ui {
class OsnOkno;
}

void vivod();

class OsnOkno : public QDialog
{
    Q_OBJECT

public:
    explicit OsnOkno(QWidget *parent = nullptr);
    ~OsnOkno();
    void vivod();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();


private:
    Ui::OsnOkno *ui;
    int count;
    QFile t;
    int marks = 0;
    int right;
    QTextStream stream;

};

#endif // OSNOKNO_H
