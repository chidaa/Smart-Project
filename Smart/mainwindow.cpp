#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QString login=ui->lineEdit_login->text();
    QString password=ui->lineEdit_password->text();
    if(login=="181AZE" && password=="181AZE7878")
    {
        QMessageBox::information(this,"login","login and password are correct");
        sec= new Login(this);
        sec->show();
    }
    else
      QMessageBox::information(this,"login","login and password are not correct");
}
