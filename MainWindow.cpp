#include "MainWindow.h"

MainWindow::MainWindow()
    : QMainWindow()
{
    ui.setupUi(this);
    board = new Board(ui.boardWidget);
    connect(ui.restartButton, SIGNAL(clicked()), board, SLOT(reset()));
}
