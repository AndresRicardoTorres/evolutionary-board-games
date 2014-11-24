#include "Node.h"

Node::Node(ChoicesList* code_in, int type_in) : code(code_in) , type(type_in) {
    numberValue = 0;
    allowFunctions = true;
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
        case 4:
            return functionStatement();
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
    case kMathSumCode: /// 88
        return mathSumStatement();
    case kMathSubCode: /// 89
        return mathSubStatement();
    case kMathMulCode: /// 90
        return mathMulStatement();
    case kMathDivCode: /// 91
        return mathDivStatement();
    case kNumberMathCode: /// 92
        return mathStatement();
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

bool Node::getAllowFunctions(){
    return allowFunctions;
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

bool Node::mathStatement() {
    int option = nextNumber(kMathStatementLimit);
    Node* numberNode;
    bool created = false;

    if (0 == option)
        return false;

    switch (option) {
    case 1:
        numberNode = new Node(code, kMathSumCode);
        break;
    case 2:
        numberNode = new Node(code, kMathSubCode);
        break;
    case 3:
        numberNode = new Node(code, kMathMulCode);
        break;
    case 4:
        numberNode = new Node(code, kMathDivCode);
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

bool Node::mathSumStatement() {
    Node* operatorOne = new Node(code, kNumberStatementCode);
    Node* operatorTwo = new Node(code, kNumberStatementCode);

    bool createdOne = operatorOne->create();
    bool createdTwo = operatorTwo->create();

    if (createdOne && createdTwo) {
        myChilds.push_back(operatorOne);
        myChilds.push_back(operatorTwo);
        return true;
    } else {
        delete operatorOne;
        delete operatorTwo;
        return false;
    }
}

bool Node::mathSubStatement() {
    Node* operatorOne = new Node(code, kNumberStatementCode);
    Node* operatorTwo = new Node(code, kNumberStatementCode);

    bool createdOne = operatorOne->create();
    bool createdTwo = operatorTwo->create();

    if (createdOne && createdTwo) {
        myChilds.push_back(operatorOne);
        myChilds.push_back(operatorTwo);
        return true;
    } else {
        delete operatorOne;
        delete operatorTwo;
        return false;
    }
}

bool Node::mathMulStatement() {
    Node* operatorOne = new Node(code, kNumberStatementCode);
    Node* operatorTwo = new Node(code, kNumberStatementCode);

    bool createdOne = operatorOne->create();
    bool createdTwo = operatorTwo->create();

    if (createdOne && createdTwo) {
        myChilds.push_back(operatorOne);
        myChilds.push_back(operatorTwo);
        return true;
    } else {
        delete operatorOne;
        delete operatorTwo;
        return false;
    }
}

bool Node::mathDivStatement() {
    Node* operatorOne = new Node(code, kNumberStatementCode);
    Node* operatorTwo = new Node(code, kNumberStatementCode);

    bool createdOne = operatorOne->create();
    bool createdTwo = operatorTwo->create();

    if (createdOne && createdTwo) {
        myChilds.push_back(operatorOne);
        myChilds.push_back(operatorTwo);
        return true;
    } else {
        delete operatorOne;
        delete operatorTwo;
        return false;
    }
}

bool Node::functionStatement() {
    int randomIndex = nextNumber(kFunctionLimit);
    if (randomIndex != 0) {
        numberValue = randomIndex;
        return true;
    } else {
        return true;
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
    case 4:
        numberNode = new Node(code, kNumberMathCode);
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
    int howManyNodes  = 0;
    int limitSequence = 10;

    howManyNodes = nextNumber(limitSequence);
    for (int i = 0; i < howManyNodes; i++) {
        int newType     = nextNumber(kStatementLimit);
        Node* aNode     = new Node(code, newType);
        bool isComplete = aNode->blockStatement();

        if (isComplete) {
            aNode->setAllowFunctions(getAllowFunctions());
            myChilds.push_back(aNode);
        }
        else {
            delete aNode;
        }
    }

    if (0 == myChilds.size())
        return false;
    else
        return true;
}

void Node::setAllowFunctions(bool val){
    allowFunctions = val;
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


