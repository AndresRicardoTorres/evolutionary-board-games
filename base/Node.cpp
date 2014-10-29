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
    bool createdB        = operatorB->create();

    if (createdOperator && createdA && createdB) {
        myChilds.push_back(operatorNode);
        myChilds.push_back(operatorA);
        myChilds.push_back(operatorB);
        return true;
    } else {
        delete operatorNode;
        delete operatorA;
        delete operatorB;
        return false;
    }
}

bool Node::create() {
    if (type <= kStatementLimit)
        return blockStatement();

    switch (type) {
    case kNumberValueCode: /// 93
        return numberValueStatement(kMemoryIntegerLimit);
    case kNumberReadBoardCode: /// 94
        return readBoardStatement();
    case kNumberReadMemCode: /// 95
        return readMemoryStatement();
    case kPositionValueCode: /// 96
        return numberValueStatement(kMemoryPositionLimit);
    case kNumberStatementCode: /// 97
        return numberStatement();
    case kBooleanOperatorCode: /// 98
        return numberValueStatement(kBooleanOperatorLimit);
    case kBooleanStatementCode: /// 99
        return booleanStatement();
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
        myChilds.push_back(nodeBool);
        myChilds.push_back(nodeIf);
        myChilds.push_back(nodeElse);
        return true;
       } else {
        delete nodeBool;
        delete nodeIf;
        delete nodeElse;
        return false;
       }
}

bool Node::numberStatement() {
    int option = nextNumber(kNumberStatementLimit);
    Node* numberNode;
    bool created = false;

    if (0 == option)
        return false;

    switch (option) {
    case 1:
        numberNode = new Node(code, kNumberValueCode);
        break;
    case 2:
        numberNode = new Node(code, kNumberReadBoardCode);
        break;
    case 3:
        numberNode = new Node(code, kNumberReadMemCode);
        break;
    }

    created = numberNode->create();

    if (created) {
        myChilds.push_back(numberNode);
        return true;
    } else {
        delete numberNode;
        return false;
    }
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
    Node* memoryPositionX = new Node(code, kPositionValueCode);
    Node* memoryPositionY = new Node(code, kPositionValueCode);
    bool createdPositionX = memoryPositionX->create();
    bool createdPositionY = memoryPositionY->create();

    if (createdPositionX && createdPositionY) {
        myChilds.push_back(memoryPositionX);
        myChilds.push_back(memoryPositionY);
        return true;
    } else {
        delete memoryPositionX;
        delete memoryPositionY;
        return false;
    }
}

bool Node::readMemoryStatement() {
    Node* memoryPosition = new Node(code, kPositionValueCode);
    bool createdPosition = memoryPosition->create();

    if (createdPosition) {
        myChilds.push_back(memoryPosition);
        return true;
    } else {
        delete memoryPosition;
        return false;
    }
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
    else
        return true;
}

bool Node::setMemoryStatement() {
    Node* memoryPosition = new Node(code, kPositionValueCode);
    Node* memoryNumber   = new Node(code, kNumberStatementCode);

    bool createdPosition = memoryPosition->create();
    bool createdNumber   = memoryNumber->create();

    if (createdPosition && createdNumber) {
        myChilds.push_back(memoryPosition);
        myChilds.push_back(memoryNumber);
        return true;
    } else {
        delete memoryNumber;
        delete memoryPosition;
        return false;
    }
}
