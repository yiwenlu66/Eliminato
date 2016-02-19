#include "MainWindow.h"
#include "GameOverDialog.h"

MainWindow::MainWindow()
    : QMainWindow()
    , currentScore(0)
    , maxScore(0)
{
    ui.setupUi(this);
    board = new Board(ui.boardWidget);
    connect(ui.restartButton, SIGNAL(clicked()), board, SLOT(reset()));
    connect(board, SIGNAL(resetUiScore()), this, SLOT(resetCurrentScore()));
    connect(board, SIGNAL(increaseUiScoreBy(int)), this, SLOT(increaseScoreBy(int)));
    connect(board, SIGNAL(gameOver()), this, SLOT(gameOver()));
    connect(this, SIGNAL(resetBoard()), board, SLOT(reset()));
}

int MainWindow::increaseScoreBy(int delta)
{
    currentScore += delta;
    ui.currentScoreLabel->setText(QString::number(currentScore));
    if (currentScore > maxScore) {
        maxScore = currentScore;
        ui.maxScoreLabel->setText(QString::number(maxScore));
    }
    return currentScore;
}

void MainWindow::resetCurrentScore()
{
    currentScore = 0;
    ui.currentScoreLabel->setText(QString::number(currentScore));
}

void MainWindow::gameOver()
{
    GameOverDialog dlg(this);
    if (dlg.exec() == QDialog::Accepted)
        emit resetBoard();
}
