#include "tile.h"

void Tile::tileDisplay()
{
    if (this->color)
        this->setStyleSheet("QLabel {background-color: rgb(120, 120, 90);}");
    else
        this->setStyleSheet("QLabel {background-color: rgb(211, 211, 158);}");
}
