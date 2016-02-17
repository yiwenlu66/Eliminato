#ifndef TILE_H
#define TILE_H
#include <QLabel>

class Tile: public QLabel
{
    public:
        int color;
        Tile(QWidget *pParent=0, Qt::WindowFlags f=0): QLabel(pParent, f) {};
        void tileDisplay();
};

#endif
