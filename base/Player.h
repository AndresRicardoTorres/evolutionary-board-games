#ifndef PLAYER_H
#define PLAYER_H

#include <boost/tuple/tuple.hpp>
#include <list>

#include "VirtualMachine.h"

typedef boost::tuple<int, int, int> nextMove;
typedef std::list<int> choicesList;

class Player
{
    public:
        Player(choicesList code);
        virtual ~Player();
        nextMove run(int** board);
    protected:
    private:
        VirtualMachine* vm;
};

#endif // PLAYER_H
