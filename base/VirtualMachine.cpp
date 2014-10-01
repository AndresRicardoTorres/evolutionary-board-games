#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(choicesList code) {
    state = 0;
    programTree = new Node(code);
    bool isComplete = programTree->create(1);
    if(isComplete)
        state = 1;

    //printCode(programTree, 0);
    memory = new int[kMemoryLimitPosition];
    for (int i = 0; i < kMemoryLimitPosition; i++){
        memory[i] = 0;
    }
}

VirtualMachine::~VirtualMachine(){
    delete programTree;
    delete[] memory;
}

nextMove VirtualMachine::run(int** board){

    for (int i = 0; i < kMemoryLimitPosition; i++){
        memory[i] = 0;
    }

    switch(state){
    case 0:
        return boost::tuples::make_tuple(0, 0, 0);
        break;
    case 1:
        execute(programTree);
        return boost::tuples::make_tuple(memory[0], memory[1], memory[2]);
        break;
    }
    if(board[0][0])
        return boost::tuples::make_tuple(0, 0, 0);
    return boost::tuples::make_tuple(0, 0, 0);
}


void VirtualMachine::execute(Node* aNode) {
    std::vector<Node*> childs;
    switch(aNode->getType()){
    case 1:
        childs = aNode->getChilds();
        for( unsigned int i = 0; i < childs.size(); i++) {
            execute(childs[i]);
        }
        break;
    case 2:
        int a = aNode->getMemoryPosition();
        int b = aNode->getMemoryNumber();
        memory[a] = b;
        break;
    }
}

#include <iostream>
void VirtualMachine::printCode(Node* aNode, unsigned int indentation) {
    if(0 == indentation)
            std::cout << "CODE" <<std::endl;
    std::cout << std::endl;
    for( unsigned int i = 0; i < indentation; i++) {
        std::cout << "_";
    }
    std::vector<Node*> childs;
    switch(aNode->getType()){
    case 1:
        std::cout << "|";
        childs = aNode->getChilds();
        for( unsigned int i = 0; i < childs.size(); i++) {
            printCode(childs[i], indentation + 1 );
        }
        break;
    case 2:
        int a = aNode->getMemoryPosition();
        int b = aNode->getMemoryNumber();
        std::cout << "SET " << a << " = " << b;
        break;
    }
}
