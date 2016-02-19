#ifndef GAMEOVERDIALOG_H
#define GAMEOVERDIALOG_H

#include <QDialog>
#include "ui_gameoverdialog.h"

class GameOverDialog : public QDialog {
public:
    GameOverDialog(QWidget* parent = 0);

private:
    Ui::GameOverDialog ui;
};

#endif
