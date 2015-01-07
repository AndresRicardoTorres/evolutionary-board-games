#include "Util.h"

int Util::modular(int num, int base) {
    int mod = (num % base);
    return mod;
}

int Util::modularWithoutZero(int num, int base) {
    int mod = (num % base);
    if (mod == 0) {
        mod = base;
    }
    return mod;
}
