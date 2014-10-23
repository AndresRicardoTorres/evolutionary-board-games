#include "Node.h"

Node::Node(ChoicesList* code_in, int type_in) : code(code_in) , type(type_in) {
    numberValue = 0;
}

Node::~Node() {
    for (unsigned int i = 0; i < myChilds.size(); i++) {
        delete myChilds[i];
    }
}

bool Node::blockStatement() {
    switch (type) {
        case 1:
            return sequenceStatement();
        case 2:
            return setMemoryStatement();
        case 3:
            return readMemoryStatement();
        case 4:
            return readBoardStatement();
        case 5:
            return ifStatement();
        default:
            return false;
        }
    return true;
}

bool Node::booleanStatement() {
    /// 1.<  2.>  3.==

    Node* operatorNode = new Node(code, kBooleanOperatorCode);
    Node* operatorA    = new Node(code, kNumberStatementCode);
    Node* operatorB    = new Node(code, kNumberStatementCode);

    bool createdOperator = operatorNode->create();
    bool createdA        = operatorA->create();
    bool createdB        = operatorA->create();

    if (createdOperator && createdA && createdB) {
        delete operatorNode;
        delete operatorA;
        delete operatorB;
        return false;
    }

    myChilds.push_back(operatorNode);
    myChilds.push_back(operatorA);
    myChilds.push_back(operatorB);

    return true;
}

bool Node::create() {
    if (type <= kStatementLimit)
        return blockStatement();

    switch (type) {
        case kBooleanStatementCode:
            return booleanStatement();
        case kBooleanOperatorCode:
            return numberValueStatement(kBooleanOperatorCode);
        case kNumberStatementCode:
            return numberStatement();
        case kPositionStatementCode:
            return numberValueStatement(kMemoryPositionLimit);
    }
    return false;
}

std::vector<Node*> Node::getChilds() {
    return myChilds;
}

int Node::getNumberValue() {
    return numberValue;
}

int Node::getType() {
    return type;
}

bool Node::ifStatement() {
    int newTypeIf   = nextNumber(kStatementLimit);
    int newTypeElse = nextNumber(kStatementLimit);
    Node* nodeBool = new Node(code, kBooleanStatementCode);
    Node* nodeIf   = new Node(code, newTypeIf);
    Node* nodeElse = new Node(code, newTypeElse);

    bool createdBool = nodeBool->create();
    bool createdIf   = nodeIf->create();
    bool createdElse = nodeElse->create();

    if (newTypeIf != 0 && newTypeElse != 0 && createdBool && createdElse
       && createdIf) {
        delete nodeBool;
        delete nodeIf;
        delete nodeElse;
       }

    myChilds.push_back(nodeBool);
    myChilds.push_back(nodeIf);
    myChilds.push_back(nodeElse);

    return true;
}

bool Node::numberStatement() {
    return true;
}

bool Node::numberValueStatement(int limit) {
    int option = nextNumber(limit);
    if (option == 0) {
        return false;
    } else {
        numberValue = option;
        return true;
    }
}

int Node::nextNumber(int mod) {
    return code->nextNumber(mod);
}

bool Node::readBoardStatement() {
    return true;
}

bool Node::readMemoryStatement() {
    return true;
}

bool Node::sequenceStatement() {
    int howManyNodes     = 0;
    int limitSequence    = 10;

    howManyNodes = nextNumber(limitSequence);
    for (int i = 0; i < howManyNodes; i++) {
        int newType     = nextNumber(kStatementLimit);
        Node* aNode     = new Node(code, newType);
        bool isComplete = aNode->blockStatement();
        if (isComplete)
            myChilds.push_back(aNode);
        else
            delete aNode;
    }

    if (0 == myChilds.size())
        return false;
    return true;
}

bool Node::setMemoryStatement() {
    Node* memoryPosition = new Node(code, kPositionStatementCode);
    Node* memoryNumber   = new Node(code, kNumberStatementCode);

    bool createdPosition = memoryPosition->create();
    bool createdNumber   = memoryNumber->create();

    if (createdPosition && createdNumber) {
        delete memoryNumber;
        delete memoryPosition;
        return false;
    }
    return true;
}
