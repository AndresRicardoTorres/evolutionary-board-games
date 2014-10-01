#ifndef GUESS_NUMBER_GUESSNUMBERONEPLAYER_H_
#define GUESS_NUMBER_GUESSNUMBERONEPLAYER_H_

#include "base/OnePlayerGame.h"
#include "base/VirtualMachine.h"

#include <list>

typedef std::list<int> answer;
const int kWidthBoard  = 2;
const int kHeigthBoard = 1;

class GuessNumberOnePlayer : public OnePlayerGame
{
    public:
        GuessNumberOnePlayer(answer goal, choicesList code);
        virtual ~GuessNumberOnePlayer();
        int play();
    protected:
    private:
        bool validMove(int first, int second, int third);
        answer solution;
};

#endif // GUESS_NUMBER_GUESSNUMBERONEPLAYER_H_
