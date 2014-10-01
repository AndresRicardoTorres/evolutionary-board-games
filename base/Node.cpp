#include "Node.h"

Node::Node(choicesList code_in) : code(code_in) {
    complete       = false;
    type           = 0;
    memoryNumber   = 0;
    memoryPosition = 0;
    }

Node::~Node() {
    for ( unsigned int i = 0; i < myChilds.size(); i++) {
        delete myChilds[i];
        }
    }

int Node::nextNumber(int mod) {
    if (code.empty()) {
        return 0;
        }
    int next = (code.front() % mod);
    if (next == 0)
        next = mod;
    code.pop_front();
    return next;
    }

bool Node::create(int type_in) {
    type              = type_in;
    int limitSequence = 10;
    int howManyNodes  = 0;

    switch (type) {
        case 1:  /// Sequence
            howManyNodes = nextNumber(limitSequence);
            for (int i = 0; i < howManyNodes; i++) {
                Node* aNode     = new Node(code);
                int newType     = nextNumber(kExpressionLimit);
                bool isComplete = aNode->create(newType);
                if (isComplete)
                    myChilds.push_back(aNode);
                else
                    delete aNode;
                }
            if (0 == howManyNodes)
                return false;
            break;
        case 2:  /// Set in memory
            memoryPosition = nextNumber(kMemoryLimitPosition);
            memoryNumber   = nextNumber(kMemoryLimitInt);

            if (0 == memoryPosition || 0 == memoryNumber)
                return false;
            break;
        default:
            return false;
        }
    return true;
    }

int Node::getType() {
    return type;
    }

int Node::getMemoryPosition() {
    return memoryPosition;
    }

int Node::getMemoryNumber() {
    return memoryNumber;
    }

std::vector<Node*> Node::getChilds() {
    return myChilds;
    }
