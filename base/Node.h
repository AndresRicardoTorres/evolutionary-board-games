#ifndef BASE_NODE_H_
#define BASE_NODE_H_

#include <list>
#include <vector>

#include "base/ChoicesList.h"

const int kMemoryLimitPosition = 9;
const int kMemoryLimitInt      = 99;
const int kExpressionLimit     = 2;

class Node
{
    public:
        Node(ChoicesList* code_in);
        virtual ~Node();
        bool create(int type_in);
        int getType();
        int getMemoryPosition();
        int getMemoryNumber();
        std::vector<Node*> getChilds();
    protected:
    private:
        int nextNumber(int mod);
        //typedef std::vector<Node*> childs;
        bool complete;
        std::vector<Node*> myChilds;
        ChoicesList* code;
        int type;

        int memoryPosition;
        int memoryNumber;
};

#endif // BASE_NODE_H_
