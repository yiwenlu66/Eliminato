#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QWidget>
#include "Tile.h"

const int N = 10;
const int TILE_SIZE = 39;
const int BORDER_SIZE = 1;

class Tile;

class Board : public QObject {
    Q_OBJECT

public:
    Board(QWidget* widget);
    Tile* atPosition(int i, int j);

signals:
    void resetUiScore();
    void increaseUiScoreBy(int delta);

public slots:
    void reset();
    void scoreIncreased(int delta);

private:
    QWidget* m_widget;
    Tile* m_tile[N][N];
};

#endif
