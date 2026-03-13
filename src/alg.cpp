// Copyright 2025 NNTU-CS
#include <cstdint>
#include "alg.h"

uint64_t collatzMaxValue(uint64_t num) {
    uint64_t maxn = num;
    uint64_t x = num;
    while (x != 1) {
        if (x % 2 == 0) {
            x = x / 2;
        } else {
            x = (3 * x + 1);
        }
        if (x > maxn) {
            maxn = x;
        }
    }
    return maxn;
}

unsigned int collatzLen(uint64_t num) {
    unsigned int len = 1;
    uint64_t x = num;
    while (x != 1) {
        if (x % 2 == 0) {
            x = x / 2;
        } else {
            x = (3 * x + 1);
        }
        ++len;
    }
    return len;
}

unsigned int seqCollatz(unsigned int* maxlen, uint64_t lbound, uint64_t rbound) {
    unsigned int maxl = 0;
    unsigned int res = 0;
    for (uint64_t i = lbound; i <= rbound; ++i) {
        unsigned int len = collatzLen(i);
        if (maxl <= len) {
            maxl = len;
            res = i;
        }
    }
    *maxlen = maxl;
    return res;
}
