#include "Tile.h"
#include "Board.h"
#include <QWidget>
#include <QLabel>
#include <QQueue>
#include <ctime>

typedef Tile* (Tile::*directionFunc)();
directionFunc DIRS[4] = { &Tile::left, &Tile::right, &Tile::up, &Tile::down };

Tile::Tile(Board* board, int i, int j, QWidget* pParent, Qt::WindowFlags f)
    : QLabel(pParent, f)
    , m_board(board)
    , m_i(i)
    , m_j(j)
{
    connect(this, SIGNAL(clicked()), this, SLOT(eliminate()));
    QLabel::setAlignment(Qt::AlignCenter);
}

void Tile::mousePressEvent(QMouseEvent* event)
{
    emit clicked();
}

int Tile::color()
{
    return m_color;
}

void Tile::setColor(int color)
{
    m_color = color;
    switch (color) {
    case -1:
        // grey, temporary
        this->setStyleSheet("QLabel {background-color: rgb(180, 180, 180);}");
        break;
    case 0:
        // white
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
    for (int i = 0; i < 4; ++i) {
        Tile* neighbor = (this->*DIRS[i])();
        if (neighbor != NULL && neighbor->color() == m_color)
            return true;
    }
    return false;
}

void Tile::eliminate()
{
    if (!clickable())
        return;
    QQueue<Tile *> bfsQueue, markedQueue;
    bfsQueue.enqueue(this);
    while (!bfsQueue.empty()) {
        Tile* current = bfsQueue.dequeue();
        for (int i = 0; i < 4; ++i) {
            Tile* neighbor = (current->*DIRS[i])();
            if (neighbor != NULL && neighbor->color() == current->color()
                && !bfsQueue.contains(neighbor) && !markedQueue.contains(neighbor))
                bfsQueue.enqueue(neighbor);
        }
        markedQueue.enqueue(current);
    }

    int numEliminated = markedQueue.length();

    foreach (Tile* tile, markedQueue) {
        tile->setColor(-1);
        tile->setText(QString("+%1").arg(numEliminated));
    }

    foreach (Tile* tile, markedQueue) {
        tile->repaint();
    }

    // sleep for 0.5 seconds
    clock_t t0 = clock();
    while (static_cast<double>(clock() - t0) / CLOCKS_PER_SEC < 0.5)
        ;

    foreach (Tile* tile, markedQueue) {
        tile->setColor(0);
    }
}
