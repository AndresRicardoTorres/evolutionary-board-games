#ifndef BASE_NODE_H_
#define BASE_NODE_H_

#include <list>
#include <vector>

#include "base/ChoicesList.h"

const int kMemoryPositionLimit  = 9;
const int kMemoryIntegerLimit   = 99;
const int kBooleanOperatorLimit = 3;
const int kStatementLimit       = 4;
const int kNumberStatementLimit = 4;
const int kMathStatementLimit   = 4;
const int kFunctionLimit        = 99;

const int kMathSumCode          = 88;
const int kMathSubCode          = 89;
const int kMathMulCode          = 90;
const int kMathDivCode          = 91;
const int kNumberMathCode       = 92;
const int kNumberValueCode      = 93;
const int kNumberReadBoardCode  = 94;
const int kNumberReadMemCode    = 95;
const int kPositionValueCode    = 96;
const int kNumberStatementCode  = 97;
const int kBooleanOperatorCode  = 98;
const int kBooleanStatementCode = 99;

class Node {
 public:
    Node(ChoicesList* code_in, int type_in);
    virtual ~Node();

    bool create();
    std::vector<Node*> getChilds();
    bool getAllowFunctions();
    int getNumberValue();
    int getType();
    void setAllowFunctions(bool val);

 private:
    ChoicesList* code;
    std::vector<Node*> myChilds;
    int numberValue;
    int type;
    bool allowFunctions;

    bool booleanStatement();
    bool blockStatement();
    bool functionStatement();
    bool ifStatement();
    bool mathStatement();
    bool mathSumStatement();
    bool mathSubStatement();
    bool mathMulStatement();
    bool mathDivStatement();
    int  nextNumber(int mod);
    bool numberStatement();
    bool numberValueStatement(int limit);
    bool readBoardStatement();
    bool readMemoryStatement();
    bool sequenceStatement();
    bool setMemoryStatement();

};

#endif  // BASE_NODE_H_
