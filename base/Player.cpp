#include "Player.h"

Player::Player(choicesList code){
    vm = new VirtualMachine(code);
}

Player::~Player() {
    delete vm;
}

nextMove Player::run(int** board){
    return vm->run(board);
}
