#include "Tile.h"
#include "Board.h"
#include <QWidget>
#include <QLabel>

Tile::Tile(Board* board, int i, int j, QWidget* pParent, Qt::WindowFlags f)
    : QLabel(pParent, f)
    , m_board(board)
    , m_i(i)
    , m_j(j){};

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


// edge cases will be handled by Board::atPosition

Tile* Tile::left()
{
    return m_board->atPosition(m_i, m_j - 1);
}

Tile* Tile::right()
{
    return m_board->atPosition(m_i, m_j + 1);
}

Tile* Tile::up()
{
    return m_board->atPosition(m_i - 1, m_j);
}

Tile* Tile::down()
{
    return m_board->atPosition(m_i + 1, m_j);
}

bool Tile::clickable()
{
    if (!m_color)
        return false;
    typedef Tile* (Tile::*directionFunc)();
    directionFunc directions[4] = {&Tile::left, &Tile::right, &Tile::up, &Tile::down};
    for (int i = 0; i < 4; ++i) {
        Tile* neighbor = (this->*directions[i])();
        if (neighbor != NULL && neighbor->color() == m_color)
            return true;
    }
    return false;
}
