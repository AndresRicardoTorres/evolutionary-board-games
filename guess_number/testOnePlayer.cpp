#include <iostream>
#include <list>

#include "guess_number/GuessNumberOnePlayer.h"

std::list<int> simpleGoal() {
    std::list<int> l;
    l.push_back(23);
    l.push_back(23);
    return l;
}

int case0() {
    std::list<int> code;
    std::list<int> goal;
    GuessNumberOnePlayer *objGame = new GuessNumberOnePlayer(goal, code);

    objGame->play();

    delete objGame;

    return 0;
}

int case1(){
    std::list<int> code;
    GuessNumberOnePlayer *objGame = new GuessNumberOnePlayer(simpleGoal(), code);

    objGame->play();

    delete objGame;

    return 0;
}

int case2(){
    std::list<int> testCode;
    testCode.push_back(4);
    testCode.push_back(10);
    testCode.push_back(9);
    testCode.push_back(7);
    testCode.push_back(4);
    testCode.push_back(9);
    testCode.push_back(4);
    testCode.push_back(10);
    testCode.push_back(7);
    GuessNumberOnePlayer *objGame = new GuessNumberOnePlayer(simpleGoal(), testCode);

    objGame->play();

    delete objGame;

    return 0;
}

int main() {
    case0();
    case1();
    case2();

    return 0;
}
