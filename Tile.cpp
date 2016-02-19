#include "Tile.h"
#include "Board.h"
#include <QWidget>
#include <QLabel>

Tile::Tile(Board* board, QWidget* pParent, Qt::WindowFlags f)
    : QLabel(pParent, f)
    , m_board(board){};

int Tile::color()
{
    return m_color;
}

void Tile::setColor(int color)
{
    m_color = color;
    switch (color) {
    case 0:
        // grey
        this->setStyleSheet("QLabel {background-color: rgb(255, 255, 255);}");
        break;
    case 1:
        // red
        this->setStyleSheet("QLabel {background-color: rgb(244, 78, 78);}");
        break;
    case 2:
        // orange
        this->setStyleSheet("QLabel {background-color: rgb(241, 163, 12);}");
        break;
    case 3:
        // blue
        this->setStyleSheet("QLabel {background-color: rgb(40, 171, 239);}");
        break;
    case 4:
        // green
        this->setStyleSheet("QLabel {background-color: rgb(181, 207, 38);}");
        break;
    case 5:
        // purple
        this->setStyleSheet("QLabel {background-color: rgb(184, 84, 230);}");
    }
}
