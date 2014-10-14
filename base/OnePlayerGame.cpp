#include "base/OnePlayerGame.h"

OnePlayerGame::OnePlayerGame( int heigth, int width, choicesList code) {

    playerA = new Player(code);

    this->width = width;
    board = new int *[width];
    for (int i = 0; i < width; i++){
        board[i] = new int[heigth];
        board[i][0] = 0;
    }
}

OnePlayerGame::~OnePlayerGame() {
    delete playerA;

    for (int i = 0; i < width; i++){
        delete[] board[i];
    }
    delete[] board;
}

int OnePlayerGame::play() {
    return 1;
}

nextMove OnePlayerGame::runPlayerA() {
    return playerA->run(board);
}
