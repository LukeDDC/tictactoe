#include "tictactoe.h"

TicTacToe::TicTacToe()
{
    int game[3][3];
    char players[2] = { 'X', 'Y' };
    currentPlayer = 'X';
    for (int row = 0; row < 3; ++row) {
        for (int column = 0; column < 3; ++column) {
            game[row][column] = 0;
        }
    }
}

char TicTacToe::play(int x, int y)
{
    char playedBy = getActualPlayer();
    switchPlayer();
    return playedBy;
}


char TicTacToe::getActualPlayer()
{
    return this->currentPlayer;
}


void TicTacToe::switchPlayer()
{
    if(getActualPlayer() == 'X')
        this->currentPlayer = 'Y';
    else
        this->currentPlayer = 'X';
}
