#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>

extern Manager *m;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap pix(":/images/openingpic.jpg");
    ui->label->setPixmap(pix.scaled(1000,1000,Qt::KeepAspectRatio));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    this->close();
//    Manager *manager1= new Manager;
//    manager1->view.show();
    m=new Manager;
    m->view.show();

}

