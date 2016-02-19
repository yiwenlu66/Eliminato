#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QWidget>
#include "Tile.h"

const int N = 10;
const int TILE_SIZE = 39;
const int BORDER_SIZE = 1;

class Board : public QObject {
    Q_OBJECT

public:
    Board(QWidget* widget);

public slots:
    void reset();

private:
    QWidget* widget;
    Tile* m_tile[N][N];
};

#endif
