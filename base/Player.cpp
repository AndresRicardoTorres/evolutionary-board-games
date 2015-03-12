#include "Player.h"

Player::Player(choicesList code) {
    cl = new ChoicesList(code);
    vm = new VirtualMachine(cl);
}

Player::~Player() {
    delete vm;
    delete cl;
}

nextMove Player::run(int** board, int height, int width) {
    return vm->run(board, height, width);
}
