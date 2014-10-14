#include "Player.h"

Player::Player(choicesList code){
    cl = new ChoicesList(code);
    vm = new VirtualMachine(cl);
}

Player::~Player() {
    delete vm;
    delete cl;
}

nextMove Player::run(int** board){
    return vm->run(board);
}
