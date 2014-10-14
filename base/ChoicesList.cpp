#include "base/ChoicesList.h"

ChoicesList::ChoicesList(std::list<int> aList) : code(aList) {
}

ChoicesList::~ChoicesList() {}

///#include <iostream>
int ChoicesList::nextNumber(int base) {
    if (code.empty()) {
        return 0;
    }
    int next = (code.front() % base);
    if (next == 0) {
        next = base;
    }

    ///std::cout << " nextNumber() " << std::endl;
    ///std::cout << " code.front " << code.front() << std::endl;
    ///std::cout << " next "  << next << std::endl;

    code.pop_front();
    return next;
}
