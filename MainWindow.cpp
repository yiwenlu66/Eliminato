#include "MainWindow.h"

MainWindow::MainWindow()
    : QMainWindow()
{
    ui.setupUi(this);
    createBoard();
}

void MainWindow::createBoard()
{
    QWidget* baseWidget = ui.boardWidget;
    int i, j, hor, ver;
    ver = 0;
    for (i = 0; i < N; ++i) {
        hor = 0;
        for (j = 0; j < N; ++j) {
            m_tile[i][j] = new Tile(baseWidget);
            m_tile[i][j]->setGeometry(hor, ver, TILE_SIZE, TILE_SIZE);
            hor += TILE_SIZE;
        }
        ver += TILE_SIZE;
    }
    resetBoard();
}

void MainWindow::resetBoard()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            m_tile[i][j]->setColor((i + j) % 6);
}
