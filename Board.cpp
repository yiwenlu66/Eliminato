#include "Board.h"
#include <cstdlib>
#include <ctime>
#include <QWidget>
#include <cassert>
#include <algorithm>

Board::Board(QWidget* widget)
    : m_widget(widget)
{
    int i, j, hor, ver;
    ver = 0;
    Tile::s_board = this;
    for (i = 0; i < N; ++i) {
        hor = 0;
        for (j = 0; j < N; ++j) {
            /*
             * Tiles are arranged in this order:
             * .
             * .                .
             * .              .
             * [0][1]       .
             * [0][0] [1][0]  . . .
             */
            Tile* tile = new Tile(j, N - 1 - i, widget);
            tile->setGeometry(hor, ver, TILE_SIZE, TILE_SIZE);
            m_tile[j][N - 1 - i] = tile;
            hor += (TILE_SIZE + BORDER_SIZE);
        }
        ver += (TILE_SIZE + BORDER_SIZE);
    }
    reset();
}

QList<int> Board::getDividingPoints()
{
    bool legal = true;
    while (true) {
        QList<int> dividingPoints;
        for (int i = 0; i < NUM_COLORS - 1; ++i)
            dividingPoints.append(std::rand());
        dividingPoints.append(0);
        dividingPoints.append(INFINITY);
        std::sort(dividingPoints.begin(), dividingPoints.end());
        for (int i = 0; i < NUM_COLORS; ++i) {
            // check whether the random is too uneven
            if (dividingPoints[i + 1] - dividingPoints[i] > MAX_DISTANCE
                || dividingPoints[i + 1] - dividingPoints[i] < MIN_DISTANCE) {
                legal = false;
            }
        }
        if (legal)
            return dividingPoints;
        legal = true;
    }
}

void Board::reset()
{
    std::srand(std::time(0));
    QList<int> dividingPoints = getDividingPoints();
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j) {
            int currentRand = std::rand();
            for (int dividingPointIndex = 0; dividingPointIndex < NUM_COLORS; ++dividingPointIndex) {
                if (dividingPoints[dividingPointIndex] <= currentRand
                    && currentRand <= dividingPoints[dividingPointIndex + 1]) {
                    m_tile[i][j]->setColor(dividingPointIndex + 1);
                }
            }
        }
    emit resetUiScore();
}

Tile* Board::atPosition(int i, int j)
{
    if (0 <= i && i < N && 0 <= j && j < N)
        return m_tile[i][j];
    return NULL;
}

void Board::scoreIncreased(int delta)
{
    emit increaseUiScoreBy(delta);
}

void Board::fall()
{
    for (int i = 0; i < N; ++i)
        fallDown(i);
    fallLeft();
    if (isGameOver())
        emit gameOver();
}

void Board::fallDown(int columnIndex)
{
    Tile** column = m_tile[columnIndex];
    int frontIndex = 0, rearIndex = 0;
    while (true) {
        while (rearIndex < N) {
            if (column[rearIndex]->color())
                ++rearIndex;
            else
                break;
        }
        if (rearIndex == N)
            break;
        frontIndex = rearIndex + 1;
        while (frontIndex < N) {
            if (!column[frontIndex]->color())
                ++frontIndex;
            else
                break;
        }
        if (frontIndex == N)
            break;
        moveTile(columnIndex, frontIndex, columnIndex, rearIndex);
    }
}

void Board::fallLeft()
{
    int frontIndex = 0, rearIndex = 0;
    while (true) {
        while (rearIndex < N) {
            if (m_tile[rearIndex][0]->color())
                ++rearIndex;
            else
                break;
        }
        if (rearIndex == N)
            break;
        frontIndex = rearIndex + 1;
        while (frontIndex < N) {
            if (!m_tile[frontIndex][0]->color())
                ++frontIndex;
            else
                break;
        }
        if (frontIndex == N)
            break;
        moveColumn(frontIndex, rearIndex);
    }
}

void Board::moveColumn(int oldI, int newI)
{
    assert(!m_tile[newI][0]->color());
    for (int j = 0; j < N; ++j)
        moveTile(oldI, j, newI, j);
}

void Board::moveTile(int oldI, int oldJ, int newI, int newJ)
{
    assert(!m_tile[newI][newJ]->color());
    m_tile[newI][newJ]->setColor(m_tile[oldI][oldJ]->color());
    m_tile[oldI][oldJ]->setColor(0);
}

bool Board::isGameOver()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (m_tile[i][j]->clickable())
                return false;
    return true;
}
