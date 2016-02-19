#ifndef TILE_H
#define TILE_H

#include <QLabel>
#include "Board.h"

class Board;

class Tile : public QLabel {
public:
    Tile(Board* board, QWidget* pParent = 0, Qt::WindowFlags f = 0);
    int color();
    void setColor(int color);

private:
    Board* m_board;
    int m_color;
};

#endif
