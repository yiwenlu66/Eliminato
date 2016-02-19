#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <QWidget>

Board::Board(QWidget* widget)
    : m_widget(widget)
{
    int i, j, hor, ver;
    ver = 0;
    for (i = 0; i < N; ++i) {
        hor = 0;
        for (j = 0; j < N; ++j) {
            Tile* tile = new Tile(this, i, j, widget);
            tile->setGeometry(hor, ver, TILE_SIZE, TILE_SIZE);
            m_tile[i][j] = tile;
            hor += (TILE_SIZE + BORDER_SIZE);
        }
        ver += (TILE_SIZE + BORDER_SIZE);
    }
    reset();
}

void Board::reset()
{
    std::srand(std::time(0));
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            m_tile[i][j]->setColor(std::rand() % 5 + 1);
}

Tile* Board::atPosition(int i, int j)
{
    if (0 <= i && i < N && 0 <= j && j < N)
        return m_tile[i][j];
    return NULL;
}
