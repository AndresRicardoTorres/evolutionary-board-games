#include "base/ChoicesList.h"

ChoicesList::ChoicesList(std::list<int> aList) : code(aList) {
}

ChoicesList::~ChoicesList() {}

int ChoicesList::nextNumber(int base) {
    if (code.empty()) {
        return 0;
    }

    int next = Util::modularWithoutZero(code.front(), base);

    code.pop_front();
    return next;
}
