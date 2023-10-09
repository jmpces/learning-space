#include <MathFunctions.hpp>
#include <cmath>

int mypow(int base, int exponent) {
    int power = base;
    for (int i = 1; i < exponent; ++i) {
        power *= base;
    }
    return power;
}