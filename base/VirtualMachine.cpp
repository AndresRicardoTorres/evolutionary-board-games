#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(ChoicesList* code) {
    state = 0;
    programTree = new Node(code, 1);
    bool isComplete = programTree->create();
    if (isComplete)
        state = 1;

    memory = new int[kMemoryPositionLimit];
    for (int i = 0; i < kMemoryPositionLimit; i++) {
        memory[i] = 0;
    }
}

VirtualMachine::~VirtualMachine() {
    delete programTree;
    delete[] memory;
}

nextMove VirtualMachine::run(int** board_in) {
    board = board_in;
    for (int i = 0; i < kMemoryPositionLimit; i++) {
        memory[i] = 0;
    }

    switch (state) {
    case 0:
        return boost::tuples::make_tuple(0, 0, 0);
        break;
    case 1:
        execute(programTree);
        return boost::tuples::make_tuple(memory[1], memory[2], memory[3]);
        break;
    }
    if (board[0][0])
        return boost::tuples::make_tuple(0, 0, 0);
    return boost::tuples::make_tuple(0, 0, 0);
}

#include <iostream>
int VirtualMachine::execute(Node* aNode) {
    bool debug = false;
    std::vector<Node*> childs;
    childs = aNode->getChilds();

    if (debug) {
        std::cout << "TYPE " << aNode->getType() << std::endl;
    }

    switch (aNode->getType()) {
    case 1:
        if (debug) {
            std::cout << "SEQ  " << childs.size() << std::endl;
        }
        for (unsigned int i = 0; i < childs.size(); i++) {
            execute(childs[i]);
        }
        return 0;
        break;
    case 2:
        if (2 == childs.size()) {
            int a = execute(childs[0]);
            int b = execute(childs[1]);
            if (debug) {
                std::cout << "TYPE " << childs[0]->getType() << std::endl;
                std::cout << "TYPE " << childs[1]->getType() << std::endl;
                std::cout << "memory[" << a << "] =  " << b << std::endl;
            }
            memory[a] = b;
            return 0;
        }
        break;
    case 3:
        if (3 == childs.size()) {
            if (debug) {
                std::cout << "IF" << std::endl;
            }
            int condition = execute(childs[0]);
            if (condition == 1) {
                execute(childs[1]);
            } else {
                execute(childs[2]);
            }

            return 0;
        }
        break;
    case 94:
        std::cout << "childs.size()   " << childs.size() << std::endl;
        if (2 == childs.size()) {
            int a = childs[0]->getNumberValue();
            int b = childs[1]->getNumberValue();
            if (debug) {
                std::cout << "board[" << a << "][" << b << "]" << std::endl;
            }
            return board[a][b];
        }
        break;
    case 95:
        if (1 == childs.size()) {
            int a = childs[0]->getNumberValue();
            if (debug) {
                std::cout << "memory[" << a << "] " << std::endl;
            }
            return memory[a];
        }
        break;
    case 96:
        if (0 == childs.size()) {
            if (debug) {
                std::cout << "NUM   " << aNode->getNumberValue() << std::endl;
            }
            return aNode->getNumberValue();
        }
        break;
    case 97:
        if (1 == childs.size()) {
            return execute(childs[0]);
        }
        break;
    case 99:
        if (3 == childs.size()) {
            int valueA     = execute(childs[1]);
            int valueB     = execute(childs[1]);
            int comparator = childs[0]->getNumberValue();

            switch (comparator) {
            case 1:
                if (debug) {
                    std::cout << valueA << " < " << valueB << std::endl;
                }
                if (valueA < valueB)
                    return 1;
                break;
            case 2:
                if (debug) {
                    std::cout << valueA << " > " << valueB << std::endl;
                }
                if (valueA > valueB)
                    return 1;
                break;
            case 3:
                if (debug) {
                    std::cout << valueA << " == " << valueB << std::endl;
                }
                if (valueA == valueB)
                    return 1;
                break;
            }
            return 0;

        }
        break;
    default:
        return -1;
    }
    return -1;
}
