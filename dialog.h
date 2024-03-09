#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>
#include <QDebug>
#include <string>



namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();
    static QString text;




private slots:
    void on_buttonBox_accepted();




private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
