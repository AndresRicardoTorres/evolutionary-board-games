#ifndef PLAYER_H
#define PLAYER_H

#include <boost/tuple/tuple.hpp>
#include <list>

#include "base/ChoicesList.h"
#include "base/VirtualMachine.h"

typedef boost::tuple<int, int, int> nextMove;
typedef std::list<int> choicesList;

class Player
{
    public:
        Player(choicesList code);
        virtual ~Player();
        nextMove run(int** board, int height, int width);
    protected:
    private:
        VirtualMachine* vm;
        ChoicesList* cl;
};

#endif // PLAYER_H
