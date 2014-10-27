#include "guess_number/GuessNumberOnePlayer.h"

GuessNumberOnePlayer::GuessNumberOnePlayer( answer goal, choicesList code)
                                          : OnePlayerGame( kWidthBoard
                                                         , kHeigthBoard
                                                         , code )
                                          , solution(goal) {
}

GuessNumberOnePlayer::~GuessNumberOnePlayer(){
}

#include <stdlib.h>
#include <iostream>
int GuessNumberOnePlayer::play() {
    if(solution.size() != 2)
        return -1;
    int limitTime = 4;
    bool gameOver = false;

    nextMove aMove;
    while(!gameOver) {
        int first, second, third;
        aMove  = runPlayerA();
        first  = boost::tuples::get<0>(aMove);
        second = boost::tuples::get<1>(aMove);
        third  = boost::tuples::get<2>(aMove);

        if(validMove(first, second, third)){
            board[first][second] = third;

            gameOver = board[0][0] == solution.front();
            gameOver = gameOver && board[0][1] == solution.back();
        }
        limitTime--;
        gameOver = gameOver || limitTime < 0;
    }
    if (0 == board[0][0] && 0 == board[0][1]) {
        return 1000;
    }
    if (0 == board[0][0] || 0 == board[0][1]) {
        return 500;
    }
    return (abs(board[0][0] - solution.front()) +
            abs(board[0][1] - solution.back()));
}

bool GuessNumberOnePlayer::validMove(int first, int second, int third) {
    if (first != 0)
        return false;
    if (second != 0 && second != 1)
        return false;
    if (third < 0)
        return false;
    return true;
}
