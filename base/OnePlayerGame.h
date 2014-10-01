#ifndef BASE_ONEPLAYERGAME_H_
#define BASE_ONEPLAYERGAME_H_

#include <boost/tuple/tuple.hpp>
#include <list>

#include "Player.h"

typedef boost::tuple<int, int, int> nextMove;
typedef std::list<int> choicesList;

class OnePlayerGame
{
    public:
        OnePlayerGame(int heigth, int width, choicesList code);
        virtual ~OnePlayerGame();

        int play();
        nextMove runPlayerA();
    protected:
        int** board;
    private:
        Player* playerA;
        int width;
};

#endif // BASE_ONEPLAYERGAME_H_
