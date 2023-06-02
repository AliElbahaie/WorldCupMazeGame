#include "mainwindow.h"
#include <QApplication>

Manager* m;
//ali, hazem, and hedaya
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
