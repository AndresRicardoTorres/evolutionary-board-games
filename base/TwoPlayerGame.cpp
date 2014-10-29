#include "TwoPlayerGame.h"

#include <iostream>
TwoPlayerGame::TwoPlayerGame( int heigth
                            , int width
                            , choicesList codeA
                            , choicesList codeB) {
    std::cout << "playerA " << codeA.size() << std::endl;
    playerA = new Player(codeA);
    std::cout << std::endl << "playerB " << codeB.size() << std::endl;
    playerB = new Player(codeB);

    this->width  = width;
    this->heigth = heigth;
    board = new int*[width];
    for (int i = 0; i < width; i++){
        board[i] = new int[heigth];
        board[i][0] = 0;
    }
}

TwoPlayerGame::~TwoPlayerGame() {
    delete playerA;
    delete playerB;

    for (int i = 0; i < width; i++){
        delete[] board[i];
    }
    delete[] board;
}

int TwoPlayerGame::play() {
    return 1;
}

nextMove TwoPlayerGame::runPlayerA() {
    return playerA->run(board, heigth, width);
}

nextMove TwoPlayerGame::runPlayerB() {
    return playerB->run(board, heigth, width);
}
