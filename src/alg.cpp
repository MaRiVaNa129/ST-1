// Copyright 2026 UNN-CS

#include <cstdint>
#include <cmath>
#include "alg.h"

static bool isPrimeHelper(uint64_t x) {
    if (x < 2) return false;
    if (x == 2) return true;
    if (x % 2 == 0) return false;
    uint64_t root = static_cast<uint64_t>(std::sqrt(x));
    for (uint64_t d = 3; d <= root; d += 2) {
        if (x % d == 0) return false;
    }
    return true;
}

bool checkPrime(uint64_t value) {
    return isPrimeHelper(value);
}

uint64_t nPrime(uint64_t n) {
    if (n == 0) return 0; 
    uint64_t counter = 0;
    uint64_t candidate = 1;
    while (counter < n) {
        candidate++;
        if (checkPrime(candidate)) {
            counter++;
        }
    }
    return candidate;
}

uint64_t nextPrime(uint64_t value) {
    uint64_t candidate = value + 1;
    while (!checkPrime(candidate)) {
        candidate++;
    }
    return candidate;
}

uint64_t sumPrime(uint64_t hbound) {
    uint64_t total = 0;
    for (uint64_t i = 2; i < hbound; i++) {
        if (checkPrime(i)) {
            total += i;
        }
    }
    return total;
}
