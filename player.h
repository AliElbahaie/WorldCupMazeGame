#ifndef PLAYER_H
#define PLAYER_H

#include <QApplication>
#include <QGraphicsPixmapItem>
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QTimer>
#include "Pellet.h"
#include "enemy.h"
#include "bullet.h"
#include "Health.h"
#include "gameover.h"
#include "win.h"
#include <QDebug>
#include <cmath>

class Player : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
private:
    int lives;
    int data[15][15];
    int enemy_dist;
    bool invincible;
    QGraphicsView* b;
    Health* h1;
    enemy* e1;
    enemy* e2;
    QGraphicsScene* S1;
    GameOver gO;
    win w;

public:
    int rows, columns;
    Player(int board[15][15], Health* h2, QGraphicsView* c, enemy* E1, enemy* E2, QGraphicsScene* s1);
    int getPlayerLives1();
    int nearest_enemy(enemy* enem);

public slots:
    void keyPressEvent(QKeyEvent* event);

private slots:
    void timeout_evet();
};

#endif
