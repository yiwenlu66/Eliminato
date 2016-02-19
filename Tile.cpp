#include "Tile.h"

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
        this->setStyleSheet("QLabel {background-color: rgb(240, 240, 240);}");
        break;
    case 1:
        // red
        this->setStyleSheet("QLabel {background-color: rgb(255, 90, 90);}");
        break;
    case 2:
        // orange
        this->setStyleSheet("QLabel {background-color: rgb(255, 170, 0);}");
        break;
    case 3:
        // blue
        this->setStyleSheet("QLabel {background-color: rgb(90, 90, 255);}");
        break;
    case 4:
        // green
        this->setStyleSheet("QLabel {background-color: rgb(90, 255, 90);}");
        break;
    case 5:
        // purple
        this->setStyleSheet("QLabel {background-color: rgb(200, 50, 255);}");
    }
}
