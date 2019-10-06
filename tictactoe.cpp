#include "tictactoe.h"
#include "QDebug"

TicTacToe::TicTacToe()
{
    char players[2] = { 'X', 'Y' };
    currentPlayer = 'X';
    for (int row = 0; row < rows; ++row) {
        for (int column = 0; column < cols; ++column) {
            game[row][column] = '\0';
        }
    }
}

bool TicTacToe::canPlay(int x, int y)
{
    if(isGameOver() || isPositionAlreadyTaken(x, y))
        return false;

    return true;
}

char TicTacToe::play(int x, int y)
{
    char playerMark = getCurrentPlayer();
    game[x][y] = playerMark;
    switchPlayer();
    return playerMark;
}


bool TicTacToe::isPositionAlreadyTaken(int x, int y)
{
    if(game[x][y] != '\0')
        return true;

    return false;
}

char TicTacToe::getCurrentPlayer()
{
    return this->currentPlayer;
}


void TicTacToe::switchPlayer()
{
    if(getCurrentPlayer() == 'X')
        this->currentPlayer = 'Y';
    else
        this->currentPlayer = 'X';
}

bool TicTacToe::isGameOver()
{
    if(verticalWin() || horizontalWin() || diagonalWin() || haveWeBoringTied()) {
        return true;
    }

    return false;
}

bool TicTacToe::haveWeBoringTied() {
    if(!isAnythigEmpty())
        return true;

    return false;
}

bool TicTacToe::isAnythigEmpty()
{
    for (int row = 0; row < rows; row++)
        for (int col = 0; col < cols; col++)
            if (game[row][col] == '\0')
                return true;

    return false;
}


bool TicTacToe::diagonalWin()
{
    if(checkPrimaryDiagonalWin())
    {
        winnerMark = game[1][1];
        return true;
    } else if (checkSecondaryDiagonalWin())
    {
        winnerMark = game[1][1];
        return true;
    }

    return false;
}

bool TicTacToe::checkSecondaryDiagonalWin()
{
    if(game[2][0] == '\0' || game[0][2] == '\0' || game[1][1] == '\0')
        return false;
    if(game[2][0] == game[1][1] && game[1][1] == game[0][2])
        return true;
    return false;
}

bool TicTacToe::checkPrimaryDiagonalWin()
{
    if(game[0][0] == '\0' || game[1][1] == '\0' || game[2][2] == '\0')
        return false;
    if(game[0][0] == game[1][1] && game[1][1] == game[2][2])
        return true;
    return false;
}

bool TicTacToe::horizontalWin()
{
    for (int row = 0; row < rows; row++) {
        if(checkColsOfRow(row))
        {
            winnerMark = game[row][0];
            return true;
        }
    }

    return false;
}

bool TicTacToe::verticalWin()
{
    for (int col = 0; col < cols; col++)
        if(checkRowsOfCol(col))
        {
            winnerMark = game[0][col];
            return true;
        }

    return false;
}

bool TicTacToe::checkColsOfRow(int row)
{
    char previousPlay = game[row][0];
    for (int col = 1; col < cols; col++)
        if(game[row][col] != previousPlay || game[row][col] == '\0' || previousPlay == '\0')
            return false;

    return true;
}

bool TicTacToe::checkRowsOfCol(int col)
{
    char previousPlay = game[0][col];

    for (int row = 0; row < rows; row++)
        if (game[row][col] != previousPlay || game[row][col] == '\0' || previousPlay == '\0')
            return false;

    return true;
}

char TicTacToe::getWinner()
{
    return this->winnerMark;
}
