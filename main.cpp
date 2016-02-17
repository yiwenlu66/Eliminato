#include <QApplication>
#include <QWidget>
#include "tile.h"

const int BOARD_SIZE = 10;
const int TILE_SIZE = 48;

Tile *tile[BOARD_SIZE][BOARD_SIZE] = { { NULL } };

void chessBoard(QWidget *baseWidget, Tile *tile[BOARD_SIZE][BOARD_SIZE])
{
    int i, j, hor, ver;
    ver = 125;
    for (i = 0; i < BOARD_SIZE; ++i) {
        hor = 350;
        for (j = 0; j < BOARD_SIZE; ++j) {
            tile[i][j] = new Tile(baseWidget);
            tile[i][j]->color = (i + j) % 2;
            tile[i][j]->tileDisplay();
            tile[i][j]->setGeometry(hor, ver, TILE_SIZE, TILE_SIZE);
            hor += TILE_SIZE;
        }
        ver += TILE_SIZE;
    }
}

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QWidget *myWidget = new QWidget();
    myWidget->setGeometry(0, 0, 1370, 700);
    chessBoard(myWidget, tile);
    myWidget->show();
    return app.exec();
}
