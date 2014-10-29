#ifndef BASE_CHOICESLIST_H_
#define BASE_CHOICESLIST_H_

#include <list>

#include "base/Util.h"

class ChoicesList {
 public:
    ChoicesList(std::list<int> aList);
    virtual ~ChoicesList();
    int nextNumber(int base);
 private:
    std::list<int> code;
};

#endif  // BASE_CHOICESLIST_H_
