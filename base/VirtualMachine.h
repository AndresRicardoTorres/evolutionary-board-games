#ifndef VIRTUALMACHINE_H
#define VIRTUALMACHINE_H

#include <boost/tuple/tuple.hpp>
#include "mongo/client/dbclient.h"
#include <list>
#include <string>
#include <vector>

#include "base/Node.h"
#include "base/Util.h"

typedef boost::tuple<int, int, int> nextMove;

class VirtualMachine
{
    public:
        VirtualMachine(ChoicesList* code);
        virtual ~VirtualMachine();
        nextMove run(int** board_in, int height, int width);
    protected:
    private:
        int execute(Node* aNode);
        int state;
        Node* programTree;
        int* memory;
        int** board;
        int boardHeight;
        int boardWidth;
        mongo::DBClientConnection mongoConnection;
};

#endif // VIRTUALMACHINE_H
