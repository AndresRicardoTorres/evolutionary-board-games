#include <list>
#include <iostream>

#include "base/ChoicesList.h"
#include "base/Node.h"
#include "base/OnePlayerGame.h"
#include "base/Player.h"
#include "base/VirtualMachine.h"

std::list <int> listCase0(){
    std::list <int> testCode;
    return testCode;
}

std::list <int> listCase3(){
    std::list <int> testCode;
    testCode.push_back(8);
    testCode.push_back(6);
    testCode.push_back(10);
    testCode.push_back(2);
    testCode.push_back(7);
    testCode.push_back(6);
    testCode.push_back(2);
    testCode.push_back(6);
    testCode.push_back(1);
    testCode.push_back(5);
    return testCode;
}

std::list <int> listCase10(){
    std::list <int> testCode;
    testCode.push_back(4);
    testCode.push_back(10);
    testCode.push_back(9);
    testCode.push_back(7);
    testCode.push_back(4);
    testCode.push_back(9);
    testCode.push_back(4);
    testCode.push_back(10);
    testCode.push_back(7);
    testCode.push_back(2);
    return testCode;
}

ChoicesList* case0() {
    ChoicesList* cl = new ChoicesList(listCase0());
    return cl;
}

ChoicesList* case1() {
    std::list <int> testCode;
    testCode.push_back(4);
    testCode.push_back(10);
    testCode.push_back(9);
    ChoicesList* cl = new ChoicesList(testCode);
    return cl;
}

ChoicesList* case2() {
    std::list <int> testCode;
    testCode.push_back(4);
    testCode.push_back(10);
    testCode.push_back(9);
    testCode.push_back(7);
    testCode.push_back(4);
    testCode.push_back(9);
    testCode.push_back(4);
    testCode.push_back(10);
    testCode.push_back(7);
    ChoicesList* cl = new ChoicesList(testCode);
    return cl;
}

ChoicesList* case3() {
    ChoicesList* cl = new ChoicesList(listCase3());
    return cl;
}

ChoicesList* case10() {
    ChoicesList* cl = new ChoicesList(listCase10());
    return cl;
}

int** emptyBoard(int width, int heigth) {
    int ** board = new int *[width];
    for (int i = 0; i < width; i++){
        board[i] = new int[heigth];
        board[i][0] = 0;
    }
    return board;
}

void deleteBoard(int** board, int width, int heigth) {
   for (int i = 0; i < width; i++){
        delete[] board[i];
    }
    delete[] board;
}

int testNodes2() {
    ChoicesList* cl = case2();
    Node* programTree = new Node(cl, 1);
    programTree->create();

    std::vector<Node*> childs = programTree->getChilds();

    delete cl;
    delete programTree;
    if(childs.size() != 4)
       return 1;
    return 0;
}

int testNodes3() {
    ChoicesList* cl = case3();
    Node* programTree = new Node(cl, 1);
    bool isComplete = programTree->create();
    if(isComplete)
        std::cout << "complete";
    else
        std::cout << "incomplete";
    std::vector<Node*> childs = programTree->getChilds();

    delete cl;
    delete programTree;

    return 0;
}

int testNodes10() {
    ChoicesList* cl = case10();
    Node* programTree = new Node(cl, 1);
    programTree->create();

    std::vector<Node*> childs = programTree->getChilds();

    delete cl;
    delete programTree;
    return 0;
}

int testVM0() {
    ChoicesList* cl = case0();
    VirtualMachine* vm = new VirtualMachine(cl);
    int ** b = emptyBoard(2, 2);
    vm->run(b);
    deleteBoard(b, 2, 2);
    delete cl;
    delete vm;
    return 0;
}

int testVM1() {
    ChoicesList* cl = case1();
    VirtualMachine* vm = new VirtualMachine(cl);
    int ** b = emptyBoard(2, 2);
    vm->run(b);
    deleteBoard(b, 2, 2);
    delete cl;
    delete vm;
    return 0;
}

int testVM2() {
    ChoicesList* cl = case2();
    VirtualMachine* vm = new VirtualMachine(cl);
    int ** b = emptyBoard(2, 2);
    vm->run(b);
    deleteBoard(b, 2, 2);
    delete cl;
    delete vm;
    return 0;
}

int testVM3() {
    ChoicesList* cl = case3();
    VirtualMachine* vm = new VirtualMachine(cl);
    int ** b = emptyBoard(2, 2);
    vm->run(b);
    deleteBoard(b, 2, 2);
    delete cl;
    delete vm;
    return 0;
}

int testVM10() {
    ChoicesList* cl = case10();
    VirtualMachine* vm = new VirtualMachine(cl);
    int ** b = emptyBoard(2, 2);
    vm->run(b);
    deleteBoard(b, 2, 2);
    delete cl;
    delete vm;
    return 0;
}

int testBoards() {
    int ** board = emptyBoard(2, 2);
    deleteBoard(board ,2 ,2);
    return 0;
}

int testPlayer0() {
    Player* p = new Player(listCase0());
    int ** board = emptyBoard(2, 2);

    p->run(board);

    deleteBoard(board ,2 ,2);
    delete p;

    return 0;
}

int testPlayer10() {
    Player* p = new Player(listCase10());
    int ** board = emptyBoard(2, 2);

    p->run(board);

    deleteBoard(board ,2 ,2);
    delete p;

    return 0;
}

int testOneGame10() {
    OnePlayerGame* opg = new OnePlayerGame(3, 3, listCase10());

    opg->runPlayerA();

    delete opg;

    return 0;
}

int testOneGame10Several() {
    OnePlayerGame* opg = new OnePlayerGame(3, 3, listCase10());
    for( unsigned int i = 0; i < 10; i++){
        opg->runPlayerA();
    }

    delete opg;

    return 0;
}

void msg(const char* msg) {
   std::cout << "--- " << msg << " ---" << std::endl;
}
int main() {
//    testBoards();
//
//    msg("Test 0");
//    testVM0();
//    testPlayer0();
//
//    msg("Test 1");
//    testVM1();
//
//    msg("Test 2");
//    testNodes2();
//    testVM2();
//
    msg("Test 3");
//    testNodes3();
    testVM3();
//
//    msg("Test 10");
//    testNodes10();
//    testVM10();
//    testPlayer10();
//    testOneGame10();
//    testOneGame10Several();

    return 0;
}
