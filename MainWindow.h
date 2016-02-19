#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ui_mainwindow.h"
#include "Board.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow();

public slots:
    void resetCurrentScore();
    int increaseScoreBy(int delta);

private:
    Board* board;
    Ui::MainWindow ui;
    int currentScore, maxScore;
};

#endif
