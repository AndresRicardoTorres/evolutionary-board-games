#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(ChoicesList* code) {
    state = 0;
    programTree = new Node(code);
    bool isComplete = programTree->create(1);
    if(isComplete)
        state = 1;

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
        return boost::tuples::make_tuple(memory[1], memory[2], memory[3]);
        break;
    }
    if(board[0][0])
        return boost::tuples::make_tuple(0, 0, 0);
    return boost::tuples::make_tuple(0, 0, 0);
}

///#include <iostream>
void VirtualMachine::execute(Node* aNode) {
    std::vector<Node*> childs;
    ///std::cout << "aNode->getType()" << aNode->getType() << std::endl;
    switch(aNode->getType()){
    case 1:
        childs = aNode->getChilds();
        ///std::cout << "childs.size()" << childs.size() << std::endl;
        for( unsigned int i = 0; i < childs.size(); i++) {
            execute(childs[i]);
        }
        break;
    case 2:
        int a = aNode->getMemoryPosition();
        int b = aNode->getMemoryNumber();
        ///std::cout << "memory[" << a << "] =  " << b << std::endl;
        memory[a] = b;
        break;
    }
}
