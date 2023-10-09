// sample use case of __uint128_t in 64-bit compilers

#include <iostream>

int main() {
    __uint128_t a = 0xffffffffffffffff, b = 0xffffffffffffffff;
    __uint128_t c = a * b;

    unsigned long hi = (c >> 64), lo = c;

    printf("%016lx %016lx\n",hi,lo);
    return 0;
}
