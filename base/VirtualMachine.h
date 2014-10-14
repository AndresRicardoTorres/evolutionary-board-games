#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <boost/tuple/tuple.hpp>
#include <string>
#include <list>

#include "Node.h"

typedef boost::tuple<int, int, int> nextMove;

class VirtualMachine
{
    public:
        VirtualMachine(ChoicesList* code);
        virtual ~VirtualMachine();
        nextMove run(int** board);
    protected:
    private:
        void execute(Node* aNode);
        int state;
        Node* programTree;
        int* memory;
};

#endif // VIRTUALMACHINE_H
