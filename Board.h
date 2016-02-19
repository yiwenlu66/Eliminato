#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QWidget>
#include <QList>
#include "Tile.h"

const int N = 10;
const int NUM_COLORS = 5;
const int TILE_SIZE = 39;
const int BORDER_SIZE = 1;

const int MAX_DISTANCE = RAND_MAX * 0.45;
const int MIN_DISTANCE = RAND_MAX * 0.07;

class Tile;

class Board : public QObject {
    Q_OBJECT

public:
    Board(QWidget* widget);
    Tile* atPosition(int i, int j);
    void fall();

signals:
    void resetUiScore();
    void increaseUiScoreBy(int delta);
    void gameOver();

public slots:
    void reset();
    void scoreIncreased(int delta);

private:
    QWidget* m_widget;
    Tile* m_tile[N][N];
    void fallDown(int columnIndex);
    void fallLeft();
    void moveTile(int oldI, int oldJ, int newI, int newJ);
    void moveColumn(int oldI, int newI);
    bool isGameOver();
    QList<int> getDividingPoints();
};

#endif
