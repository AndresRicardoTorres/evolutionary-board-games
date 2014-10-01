#ifndef TWOPLAYERGAME_H
#define TWOPLAYERGAME_H

#include <boost/tuple/tuple.hpp>
#include <list>

#include "Player.h"

typedef boost::tuple<int, int, int> nextMove;
typedef std::list<int> choicesList;

class TwoPlayerGame
{
    public:
        TwoPlayerGame( int heigth
                     , int width
                     , choicesList codeA
                     , choicesList codeB);
        virtual ~TwoPlayerGame();

        int play();
        nextMove runPlayerA();
        nextMove runPlayerB();
    protected:
        int** board;
    private:
        Player* playerA;
        Player* playerB;
        int width;
};

#endif // TWOPLAYERGAME_H
