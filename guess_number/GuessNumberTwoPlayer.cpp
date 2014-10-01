#include "GuessNumberTwoPlayer.h"
GuessNumberTwoPlayer::GuessNumberTwoPlayer( answer goal
                                          , choicesList code1
                                          , choicesList code2)
                                          : TwoPlayerGame( kWidthBoard
                                                         , kHeigthBoard
                                                         , code1
                                                         , code2 )
                                          , solution(goal) {
}

GuessNumberTwoPlayer::~GuessNumberTwoPlayer(){
}

#include <iostream>
int GuessNumberTwoPlayer::play() {
    int limitTime = 10;
    bool gameOver = false;
    bool turn     = true;
    nextMove aMove;
    while(!gameOver) {
        int first, second, third;
        if(turn) {aMove = runPlayerA(); std::cout << "-A-" << std::endl;}
        else     {aMove = runPlayerB(); std::cout << "-B-" << std::endl;}

        first  = boost::tuples::get<0>(aMove);
        second = boost::tuples::get<1>(aMove);
        third  = boost::tuples::get<2>(aMove);
        std::cout << "Move! " << first << " , " << second << " , " << third <<
        std::endl;

        if(validMove(first, second, third)){
            turn = !turn;
            board[first][second] = third;

            gameOver = board[0][0] == solution.front();
            gameOver = gameOver && board[0][1] == solution.back();
        }
        else {
            std::cout << "Invalid Move! " << std::endl;
        }
        limitTime--;
        gameOver = gameOver || limitTime < 0;
        std::cout << "TIME LIMIT " << limitTime << std::endl << std::endl;
        //std::cout << "BOARD [ " << board[0][0] << " , " << board[0][1] << " ] "
        //<< std::endl;
    }

    if(limitTime == -1)
        std::cout << "TIME OVER! " << std::endl;

    if(!turn) return 1;
         else return 2;
}

bool GuessNumberTwoPlayer::validMove(int first, int second, int third) {
    if (first != 0)
        return false;
    if (second != 0 && second != 1)
        return false;
    if (third < 0)
        return false;
    return true;
}
