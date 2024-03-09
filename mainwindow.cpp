#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setAttribute(Qt::WA_DeleteOnClose);
}

MainWindow::~MainWindow()
{
    delete ui;
}


/*void MainWindow::on_action_triggered()
{

    std::ofstream file;
    file.open("result.txt");
    file<<"result";
    file.close();
}*/

void MainWindow::on_pushButton_clicked()
{

   Dialog neww;
   neww.setModal(true);
   neww.exec();
    this->hide();
   this->close();


}
