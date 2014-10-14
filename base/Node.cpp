#include "Node.h"

Node::Node(ChoicesList* code_in) : code(code_in) {
    complete       = false;
    type           = 0;
    memoryNumber   = 0;
    memoryPosition = 0;
}

Node::~Node() {
    for (unsigned int i = 0; i < myChilds.size(); i++) {
        delete myChilds[i];
    }
}

int Node::nextNumber(int mod) {
    return code->nextNumber(mod);
}

bool Node::create(int type_in) {
    type              = type_in;
    int limitSequence = 10;
    int howManyNodes  = 0;
    bool created      = true;

    switch (type) {
        case 1:  /// Sequence
            howManyNodes = nextNumber(limitSequence);
            for (int i = 0; i < howManyNodes; i++) {
                int newType     = nextNumber(kExpressionLimit);
                Node* aNode     = new Node(code);
                bool isComplete = aNode->create(newType);
                if (isComplete)
                    myChilds.push_back(aNode);
                else
                    delete aNode;
                }
            if (0 == howManyNodes)
                created = false;
            break;
        case 2:  /// Set in memory
            memoryPosition = nextNumber(kMemoryLimitPosition);
            memoryNumber   = nextNumber(kMemoryLimitInt);

            if (0 == memoryPosition || 0 == memoryNumber)
                created = false;
            break;
        default:
            created = false;
        }
    return created;
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
