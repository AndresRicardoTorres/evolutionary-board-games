#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <boost/tuple/tuple.hpp>
#include <string>
#include <list>

#include "Node.h"

typedef std::list<int> choicesList;
typedef boost::tuple<int, int, int> nextMove;

class VirtualMachine
{
    public:
        VirtualMachine(choicesList code);
        virtual ~VirtualMachine();
        nextMove run(int** board);
    protected:
    private:
        void printCode(Node* aNode, unsigned int indentation);
        void execute(Node* aNode);
        int state;
        Node* programTree;
        int* memory;
};

#endif // VIRTUALMACHINE_H
