#include "Player.h"

Player::Player(int board[15][15], Health* h2, QGraphicsView* c, enemy* E1, enemy* E2, QGraphicsScene* s1)
{
    QPixmap image(":/images/ronaldo v2.png");
    image = image.scaledToWidth(50);
    image = image.scaledToHeight(50);
    setPixmap(image);

    b = c;
    h1 = h2;
    e1 = E1;
    e2 = E2;
    S1 = s1;

    rows = 7;
    columns = 7;
    setPos(51 + columns * 51, 50 + rows * 50);
    lives = 3;
    invincible = false;

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            data[i][j] = board[i][j];
        }
    }
}

int Player::getPlayerLives1()
{
    return lives;
}

int Player::nearest_enemy(enemy* enem)
{
    return enemy_dist = sqrt(pow((rows - (enem->row)), 2) + pow((columns - (enem->column)), 2));
}

void Player::keyPressEvent(QKeyEvent* event)
{
    if (event->key() == Qt::Key_Up && data[rows - 1][columns] >= 0)
    {
        rows--;
    }
    else if (event->key() == Qt::Key_Down && data[rows + 1][columns] >= 0)
    {
        rows++;
    }
    else if (event->key() == Qt::Key_Right && data[rows][columns + 1] >= 0)
    {
        columns++;
    }
    else if (event->key() == Qt::Key_Left && data[rows][columns - 1] >= 0)
    {
        columns--;
    }
    setPos(51 + columns * 51, 50 + rows * 50);

    QList<QGraphicsItem*> items = collidingItems();
    for (int i = 0; i < items.size(); i++)
    {
        if (typeid(*items[i]) == typeid(Pellet))
        {
            if (invincible != true)
            {
                scene()->removeItem(items[i]);
                invincible = true;
                QTimer::singleShot(10000, this, SLOT(timeout_evet()));
            }
        }
        if (typeid(*items[i]) == typeid(bullet))
        {
            scene()->removeItem(items[i]);
            if (nearest_enemy(e1) > nearest_enemy(e2))
            {
                e2->health -= 1;
                if (e2->health == 0)
                {
                    S1->removeItem(e2);
                }
            }
            else
            {
                e1->health -= 1;
                if (e1->health == 0)
                {
                    S1->removeItem(e1);
                }
            }
            if (e1->health == 0 && e2->health == 0)
            {
                b->hide();
                w.show();
            }
        }
        if (typeid(*items[i]) == typeid(enemy))
        {
            if (invincible != true)
            {
                rows = 7;
                columns = 7;
                setPos(50 + columns * 50, 50 + rows * 50);
                lives--;
                h1->displayHealth(lives);
                if (lives == 0)
                {
                    b->hide();
                    gO.show();
                }
            }
        }
    }
}

void Player::timeout_evet()
{
    invincible = false;
}
