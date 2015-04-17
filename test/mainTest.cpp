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

std::list <int> listCase1(){
    std::list <int> testCode;
    testCode.push_back(4);
    testCode.push_back(10);
    testCode.push_back(9);
    return testCode;
}

std::list <int> listCase2() {
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
    return testCode;
}

std::list <int> listCase3() {
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

std::list <int> listCase4() {
    std::list <int> testCode;
    for (unsigned int i = 1; i < 200; i++) {
            testCode.push_back(i);
    }
    return testCode;
}

std::list <int> listCase5() {
    std::list <int> testCode;
    testCode.push_back(5);
    testCode.push_back(7);
    testCode.push_back(2);
    testCode.push_back(3);
    testCode.push_back(5);
    testCode.push_back(5);
    testCode.push_back(1);
    testCode.push_back(1);
    testCode.push_back(10);
    testCode.push_back(10);
    testCode.push_back(4);
    testCode.push_back(7);
    testCode.push_back(3);
    testCode.push_back(3);
    testCode.push_back(10);
    testCode.push_back(10);
    testCode.push_back(2);
    testCode.push_back(4);
    return testCode;
}

std::list <int> listCase6() {
    std::list <int> testCode;
    testCode.push_back(1);
    testCode.push_back(2);
    testCode.push_back(1);
    testCode.push_back(1);
    testCode.push_back(10);
    return testCode;
}

std::list <int> listCase7() {
    std::list <int> testCode;
    testCode.push_back(10);
    testCode.push_back(8);
    testCode.push_back(6);
    testCode.push_back(2);
    testCode.push_back(2);
    testCode.push_back(6);
    testCode.push_back(7);
    testCode.push_back(4);
    testCode.push_back(8);
    testCode.push_back(5);
    return testCode;
}

std::list <int> listCase8() {
    std::list <int> testCode;
    testCode.push_back(4);
    testCode.push_back(2);
    testCode.push_back(3);
    testCode.push_back(7);
    testCode.push_back(1);
    testCode.push_back(1);
    testCode.push_back(9);
    testCode.push_back(7);
    testCode.push_back(8);
    testCode.push_back(5);
    testCode.push_back(2);
    testCode.push_back(2);
    testCode.push_back(4);
    testCode.push_back(5);
    return testCode;
}

std::list <int> listCase9() {
    std::list <int> testCode;
    testCode.push_back(1);
    testCode.push_back(2);
    testCode.push_back(7);
    testCode.push_back(1);
    testCode.push_back(23);
    return testCode;
}

std::list <int> listCase10() {
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

std::list <int> listCase11() {
    std::list <int> testCode;
    testCode.push_back(1);
    testCode.push_back(3);
    testCode.push_back(2);
    testCode.push_back(2);
    testCode.push_back(3);
    testCode.push_back(1);
    testCode.push_back(26);
    testCode.push_back(1);
    testCode.push_back(14);
    testCode.push_back(7);
    testCode.push_back(1);
    testCode.push_back(23);
    testCode.push_back(7);
    testCode.push_back(1);
    testCode.push_back(23);
    return testCode;
}

std::list <int> listCase12() {
    // A function with id 23
    std::list <int> testCode;
    testCode.push_back(1);
    testCode.push_back(4);
    testCode.push_back(3);
    return testCode;
}

std::list <int> listCase13() {
    // MEM[1] = 23 * 23
    std::list <int> testCode;
    testCode.push_back(1);
    testCode.push_back(2);
    testCode.push_back(1);
    testCode.push_back(4);
    testCode.push_back(3);
    testCode.push_back(1);
    testCode.push_back(23);
    testCode.push_back(1);
    testCode.push_back(23);
    return testCode;
}

ChoicesList* case0() {
    ChoicesList* cl = new ChoicesList(listCase0());
    return cl;
}

ChoicesList* case1() {
    ChoicesList* cl = new ChoicesList(listCase1());
    return cl;
}

ChoicesList* case2() {
    ChoicesList* cl = new ChoicesList(listCase2());
    return cl;
}

ChoicesList* case3() {
    ChoicesList* cl = new ChoicesList(listCase3());
    return cl;
}

ChoicesList* case4() {
    ChoicesList* cl = new ChoicesList(listCase4());
    return cl;
}

ChoicesList* case5() {
    ChoicesList* cl = new ChoicesList(listCase5());
    return cl;
}

ChoicesList* case6() {
    ChoicesList* cl = new ChoicesList(listCase6());
    return cl;
}

ChoicesList* case7() {
    ChoicesList* cl = new ChoicesList(listCase7());
    return cl;
}

ChoicesList* case8() {
    ChoicesList* cl = new ChoicesList(listCase8());
    return cl;
}

ChoicesList* case9() {
    ChoicesList* cl = new ChoicesList(listCase9());
    return cl;
}

ChoicesList* case10() {
    ChoicesList* cl = new ChoicesList(listCase10());
    return cl;
}

ChoicesList* case11() {
    return new ChoicesList(listCase11());
}


ChoicesList* case12() {
    return new ChoicesList(listCase12());
}

ChoicesList* case13() {
    return new ChoicesList(listCase13());
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
    if(!isComplete)
        std::cout << "programTree INCOMPLETE" << std::endl;
    std::vector<Node*> childs = programTree->getChilds();

    delete cl;
    delete programTree;

    return 0;
}

int testNodes4() {
    ChoicesList* cl = case4();
    Node* programTree = new Node(cl, 1);
    bool isComplete = programTree->create();
    if(!isComplete)
        std::cout << "programTree INCOMPLETE" << std::endl;
    std::vector<Node*> childs = programTree->getChilds();

    delete cl;
    delete programTree;

    return 0;
}

int testNodes5() {
    ChoicesList* cl = case5();
    Node* programTree = new Node(cl, 1);
    bool isComplete = programTree->create();
    if(!isComplete)
        std::cout << "programTree INCOMPLETE" << std::endl;
    std::vector<Node*> childs = programTree->getChilds();

    delete cl;
    delete programTree;

    return 0;
}

int testNodes6() {
    ChoicesList* cl = case6();
    Node* programTree = new Node(cl, 1);
    bool isComplete = programTree->create();
    if(!isComplete)
        std::cout << "programTree INCOMPLETE" << std::endl;
    std::vector<Node*> childs = programTree->getChilds();

    delete cl;
    delete programTree;

    return 0;
}

int testNodes7() {
    ChoicesList* cl = case7();
    Node* programTree = new Node(cl, 1);
    bool isComplete = programTree->create();
    if(!isComplete)
        std::cout << "programTree INCOMPLETE" << std::endl;
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

int testNodes13() {
    ChoicesList* cl = case13();
    Node* programTree = new Node(cl, 1);
    programTree->create();

    std::vector<Node*> childs = programTree->getChilds();

    delete cl;
    delete programTree;
    return 0;
}

int testVMBase(ChoicesList* cl) {
    VirtualMachine* vm = new VirtualMachine(cl);
    int height = 2;
    int width  = 2;
    int ** b = emptyBoard(height, width);
    vm->run(b, height, width);
    deleteBoard(b, height, width);
    delete cl;
    delete vm;
    return 0;
}

int testVM0() {
    return testVMBase(case0());
}

int testVM1() {
    return testVMBase(case1());
}

int testVM2() {
    return testVMBase(case2());
}

int testVM3() {
    return testVMBase(case3());
}

int testVM4() {
    return testVMBase(case4());
}

int testVM5() {
    return testVMBase(case5());
}

int testVM6() {
    return testVMBase(case6());
}

int testVM7() {
    return testVMBase(case7());
}

int testVM8() {
    return testVMBase(case8());
}

int testVM9() {
    return testVMBase(case9());
}

int testVM10() {
    return testVMBase(case10());
}

int testVM11() {
    return testVMBase(case11());
}

int testVM12() {
    return testVMBase(case12());
}

int testVM13() {
    return testVMBase(case13());
}

int testBoards() {
    int ** board = emptyBoard(2, 2);
    deleteBoard(board ,2 ,2);
    return 0;
}

int testPlayer0() {
    Player* p = new Player(listCase0());
    int ** board = emptyBoard(2, 2);

    p->run(board, 2, 2);

    deleteBoard(board ,2 ,2);
    delete p;

    return 0;
}

int testPlayer10() {
    Player* p = new Player(listCase10());
    int ** board = emptyBoard(2, 2);

    p->run(board, 2, 2);

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
        std::cout << "** " << i << " **" << std::endl;
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
//    msg("Test 3");
//    testNodes3();
//    testVM3();
//
//    msg("Test 4");
//    testNodes4();
//    testVM4();
//
//    msg("Test 5");
//    testVM5();
//
//    msg("Test 6");
//    testNodes6();
//    testVM6();
//
//    msg("Test 7");
//    testNodes7();
//    testVM7();

//    msg("Test 8");
//    testVM8();

//    msg("Test 9");
//    testVM9();

//    msg("Test 11");
//    testVM11();

    msg("Test 12");
    testVM12();

//    msg("Test 13");
//    testVM13();

//    msg("Test 10");
//    testNodes10();
//    testVM10();
//    testPlayer10();
//    testOneGame10();
//    testOneGame10Several();

    return 0;
}
