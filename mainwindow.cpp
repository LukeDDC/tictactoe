#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{

    ui->setupUi(this);
    ui->winnerLabel->hide();
    gameButtons = new QList<GameButton *>();
    this->game = new TicTacToe();
    for (int row = 0; row< 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            GameButton *button = new GameButton(row, column, ui->gridLayoutWidget);
            button->setText("");
            ui->gridLayout->addWidget(button, row, column);
            connect(button, SIGNAL(clicked()), this, SLOT(handleGameButtonClick()));
            gameButtons->append(button);
        }
    }
    connect(ui->resetButton, SIGNAL(clicked()), this, SLOT(handleResetButtonClick()));
}

MainWindow::~MainWindow()
{
    delete ui;
    delete game;
    delete gameButtons;
}

void MainWindow::handleGameButtonClick()
{
    GameButton *clickedButton = qobject_cast<GameButton*>(sender());

    if(game->canPlay(clickedButton->getX(), clickedButton->getY()))
    {
        char returnedValue = game->play(clickedButton->getX(), clickedButton->getY());
        clickedButton->setText(QString(returnedValue));
        if(game->isGameOver())
        {
            if(game->haveWeBoringTied())
            {
                ui->winnerLabel->setText(QString("SUCH A CRAPY GAME"));
            }
            else
            {
                ui->winnerLabel->setText(QString("PLAYER %1 HAVE WON").arg(game->getWinner()));
            }
            ui->winnerLabel->show();
        }
    }
}

void MainWindow::handleResetButtonClick()
{
    for (int i = 0; i < gameButtons->length(); i++) {
        GameButton *button = gameButtons->at(i);
        button->setText("");
    }
}
