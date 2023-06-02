#include "gameover.h"
#include "ui_gameover.h"
#include "manager.h"

GameOver::GameOver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GameOver)
{
    ui->setupUi(this);
    QPixmap pix2(":/images/ronaldo lose.jpeg");
    ui->label_2->setPixmap(pix2.scaled(800,450));
}

GameOver::~GameOver()
{
    delete ui;
}

void GameOver::on_pushButton_clicked()
{
    this->hide();
    Manager *manager1= new Manager;
    manager1->view.show();
}

void GameOver::on_pushButton_2_clicked()
{
    this->close();
}

