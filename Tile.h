#ifndef TILE_H
#define TILE_H

#include <QLabel>
#include "Board.h"

class Board;

class Tile : public QLabel {

    Q_OBJECT

public:
    Tile(Board* board, int i, int j, QWidget* pParent = 0, Qt::WindowFlags f = 0);
    int color();
    void setColor(int color);
    Tile* left();
    Tile* right();
    Tile* up();
    Tile* down();
    bool clickable();

signals:
    void clicked();

protected:
    void mousePressEvent(QMouseEvent* event);

private slots:
    void eliminate();

private:
    Board* m_board;
    int m_color;
    int m_i, m_j;
};

#endif
