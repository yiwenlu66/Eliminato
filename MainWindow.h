#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Tile.h"

const int N = 10;
const int TILE_SIZE = 40;

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

public slots:
    void resetBoard();

private:
    Tile* m_tile[N][N];
    Ui::MainWindow ui;
    void createBoard();
};

#endif
