#include "VirtualMachine.h"

VirtualMachine::VirtualMachine(ChoicesList* code) {
    state       = 0;
    boardHeight = 0;
    boardWidth  = 0;
    programTree = new Node(code, 1);
    bool isComplete = programTree->create();
    if (isComplete)
        state = 1;

    memory = new int[kMemoryPositionLimit];
    for (int i = 0; i < kMemoryPositionLimit; i++) {
        memory[i] = 0;
    }
    mongo::client::initialize();
    mongoConnection.connect("localhost");
}

VirtualMachine::~VirtualMachine() {
    delete programTree;
    delete[] memory;
}

nextMove VirtualMachine::run(int** board_in, int height, int width) {
    board       = board_in;
    boardHeight = height;
    boardWidth  = width;
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
#include <string>
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
    case 4:
        if (0 == childs.size() && aNode->getAllowFunctions()) {
            std::string collection = "reuse.functions";
            int functionsCount    = mongoConnection.count(collection);
            int indexFunction     = aNode->getNumberValue();
            int selectedFunction  = 0;
            bool isComplete       = false;

            std::string    codeProgram;
            std::vector    <mongo::BSONElement> elements;
            std::list      <int> listCode;
            std::auto_ptr  <mongo::DBClientCursor> cursor;
            mongo::BSONObj objFunction;

            ChoicesList* cl;
            Node*        aNodeFunction;

            if (debug) {
                std::cout << "count:" << functionsCount << std::endl;
                std::cout << "indexFunction:" << indexFunction << std::endl;
            }

            if (functionsCount > 0) {
                selectedFunction = Util::modularWithoutZero(indexFunction,
                                                            functionsCount);

                if (debug) {
                    std::cout << "Function" << selectedFunction << std::endl;
                }

                cursor = mongoConnection.query("reuse.functions",
                                          BSON("id" << selectedFunction));
                objFunction = cursor->next();

                elements = objFunction["code"].Array();
                for (unsigned i = 0; i < elements.size(); i++) {
                    listCode.push_back(elements.at(i).numberInt());
                }

                cl = new ChoicesList(listCode);
                aNodeFunction = new Node(cl, 1);
                aNodeFunction->setAllowFunctions(false);
                isComplete = aNodeFunction->create();

                if (isComplete) {
                    /// Mark the function as used
                    if (debug) {
                        std::cout << "Mark function " << selectedFunction
                            << std::endl;
                    }
                    mongoConnection.update("reuse.functions",
                                            BSON("id" << selectedFunction),
                                            BSON("$set" <<
                                                BSON("used" << true)));
                    execute(aNodeFunction);
                }
                delete cl;
                delete aNodeFunction;
            }
        }
        break;
    case 88:
        if (2 == childs.size()) {
            int a = execute(childs[0]);
            int b = execute(childs[1]);
            if (debug) {
                std::cout << "SUM   " << a << " + " << b << std::endl;
            }
            return a + b;
        }
        break;
    case 89:
        if (2 == childs.size()) {
            int a = execute(childs[0]);
            int b = execute(childs[1]);
            if (debug) {
                std::cout << "SUB   " << a << " - " << b << std::endl;
            }
            return a - b;
        }
        break;
    case 90:
        if (2 == childs.size()) {
            int a = execute(childs[0]);
            int b = execute(childs[1]);
            if (debug) {
                std::cout << "MUL   " << a << " * " << b << std::endl;
            }
            return a * b;
        }
        break;
    case 91:
        if (2 == childs.size()) {
            int a = execute(childs[0]);
            int b = execute(childs[1]);
            if (debug) {
                std::cout << "DIV   " << a << " / " << b << std::endl;
            }
            if (b == 0)
                return 0;
            else
                return a / b;
        }
        break;
    case 92:
        if (1 == childs.size()) {
            return execute(childs[0]);
        }
        break;
    case 93:
        if (0 == childs.size()) {
            if (debug) {
                std::cout << "NUM   " << aNode->getNumberValue() << std::endl;
            }
            return aNode->getNumberValue();
        }
    case 94:
        if (2 == childs.size()) {
            int a = childs[0]->getNumberValue();
            int b = childs[1]->getNumberValue();

            if (debug) {
                    std::cout << "HW[" << boardHeight << "][" << boardWidth << "]" << std::endl;
                std::cout << "board[" << a << "][" << b << "]" << std::endl;
            }

            a = Util::modular(a, boardHeight);
            b = Util::modular(b, boardWidth);

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
            int valueB     = execute(childs[2]);
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
