#ifndef TILE_H
#define TILE_H

#include <QLabel>
#include "Board.h"

class Board;

class Tile : public QLabel {

    Q_OBJECT

public:
    Tile(int i, int j, QWidget* pParent = 0, Qt::WindowFlags f = 0);
    static Board* s_board;
    int color();
    void setColor(int color);
    Tile* left();
    Tile* right();
    Tile* up();
    Tile* down();
    bool clickable();

signals:
    void clicked();
    void scoreIncreased(int delta);

protected:
    void mousePressEvent(QMouseEvent* event);

private slots:
    void eliminate();

private:
    int m_color;
    int m_i, m_j;
};

#endif
