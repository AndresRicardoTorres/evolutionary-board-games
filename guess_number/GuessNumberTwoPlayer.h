#ifndef GUESSNUMBERTWOPLAYER_H
#define GUESSNUMBERTWOPLAYER_H

#include "base/TwoPlayerGame.h"
#include "base/VirtualMachine.h"

#include <list>

typedef std::list<int> answer;
const int kWidthBoard  = 2;
const int kHeigthBoard = 1;

class GuessNumberTwoPlayer : public TwoPlayerGame
{
    public:
        GuessNumberTwoPlayer( answer goal
                            , choicesList code1
                            , choicesList code2);
        virtual ~GuessNumberTwoPlayer();
        int play();
    protected:
    private:
        bool validMove(int first, int second, int third);
        answer solution;
};

#endif // GUESSNUMBERTWOPLAYER_H
