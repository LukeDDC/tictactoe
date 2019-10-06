#ifndef TICTACTOE_H
#define TICTACTOE_H

class TicTacToe
{
public:
    TicTacToe();
    char play(int x, int y);
    char getActualPlayer();
private:
    char currentPlayer;
    void switchPlayer();
};

#endif // TICTACTOE_H
