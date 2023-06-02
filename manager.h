#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QApplication>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QFile>
#include <QTextStream>
#include <QGraphicsPixmapItem>
#include <QGraphicsRectItem>
#include <QDebug>
//#include <QMediaPlayer>
#include "Pellet.h"
#include "Player.h"
#include "Health.h"
//#include "graphenemy.h"

class Manager
{
public:
    QGraphicsView view;
    QGraphicsScene scene;
    int MapData[15][15];
    QGraphicsPixmapItem Maparray[15][15];
    Health health1;
    enemy* enemy1;
    enemy* enemy2;
//    GraphEnemy* enemy3;
    Player* Franklin;
    Pellet* armor1;
    Pellet* armor2;
    bullet* bullet1;
    bullet* bullet2;
    bullet* bullet3;
    bullet* bullet4;
    Manager();
};

#endif // MANAGER_H

