#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
    TicTacToe();
    char play(int x, int y);
    char getCurrentPlayer();
    char getWinner();
    bool isGameOver();
private:
    int const static rows = 3;
    int const static cols = 3;
    char game[rows][cols];
    char currentPlayer;
    char winnerMark;

    void switchPlayer();
    bool horizontalWin();
    bool verticalWin();
    bool diagonalWin();
    bool checkColsOfRow(int row);
    bool checkRowsOfCol(int col);
    bool checkPrimaryDiagonalWin();
    bool checkSecondaryDiagonalWin();
};

#endif // TICTACTOE_H
