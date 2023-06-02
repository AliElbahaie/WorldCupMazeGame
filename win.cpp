#include "win.h"
#include "ui_win.h"

win::win(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::win)
{
    ui->setupUi(this);
    QPixmap pix(":/images/ronaldo world cup.jpeg");
    ui->label->setPixmap(pix.scaled(500,500,Qt::KeepAspectRatio));
}

win::~win()
{
    delete ui;
}
