#include "manager.h"

Manager::Manager()
{
    srand(time(NULL));

    view.setFixedSize(820, 820);
    view.setWindowTitle("GTA");
    QBrush brush(Qt::darkBlue);
    view.setBackgroundBrush(brush);

    QFile file(":/Board/mapofgame.txt");
    file.open(QIODevice::ReadOnly);
    QTextStream stream(&file);

    QString temp;
    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            stream >> temp;
            MapData[i][j] = temp.toInt();
        }
    }

    QPixmap stonesImage(":/images/grass.jpg");
    stonesImage = stonesImage.scaledToWidth(50);
    stonesImage = stonesImage.scaledToHeight(50);

    QPixmap lavaImage(":/images/seats.png");
    lavaImage = lavaImage.scaledToWidth(50);
    lavaImage = lavaImage.scaledToHeight(50);

    QPixmap home(":/images/home.png");
    home = home.scaledToWidth(50);
    home = home.scaledToHeight(50);

    for (int i = 0; i < 15; i++)
    {
        for (int j = 0; j < 15; j++)
        {
            if (i == 7 && j == 7)
            {
                Maparray[i][j].setPixmap(home);
            }
            else if(MapData[i][j] == -1)
            {
                Maparray[i][j].setPixmap(lavaImage);
            }
            else
            {
                Maparray[i][j].setPixmap(stonesImage);
            }

            Maparray[i][j].setPos(50 + j * 50, 50 + i * 50);

            scene.addItem(&Maparray[i][j]);
        }
    }

    scene.addItem(&health1);

    enemy1=new enemy(MapData,13,5);
    scene.addItem(enemy1);
    enemy2=new enemy(MapData,13,9);
    scene.addItem(enemy2);

    Franklin = new Player(MapData, &health1, &view, enemy1, enemy2, &scene);
    scene.addItem(Franklin);

//    enemy3= new GraphEnemy(MapData,Franklin,13,9);
//    scene.addItem(enemy3);

    armor1=new Pellet(MapData);
    scene.addItem(armor1);
    armor2=new Pellet(MapData);
    scene.addItem(armor2);

    bullet1=new bullet(MapData,1,1);
    scene.addItem(bullet1);
    bullet2=new bullet(MapData,13,1);
    scene.addItem(bullet2);
    bullet3=new bullet(MapData,1,13);
    scene.addItem(bullet3);
    bullet4=new bullet(MapData,13,13);
    scene.addItem(bullet4);

    Franklin->setFlag(QGraphicsItem::ItemIsFocusable);
    Franklin->setFocus();

    view.setScene(&scene);
}
