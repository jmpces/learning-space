// multiplication of uint320 using __uint120_t
#include <iostream>

void printHexU320(unsigned long *uint320_arr) {
    for(size_t i=0; i<5; ++i) {
        printf("%016lx ", uint320_arr[4-i]);
    }
    std::cout << "\n";
}

void u320mul(unsigned long *multiplicand, unsigned long *multiplier, unsigned long *product) {

    __uint128_t __uint120_product[6] = {0,0,0,0,0,0};

    for(size_t i=0; i<5; ++i) {
        for(size_t j=0; j<5-i; ++j) {
            __uint120_product[i+j] += (__uint128_t)multiplicand[j] * (__uint128_t)multiplier[i];

            __uint120_product[i+j+1] += (__uint120_product[i+j] >> 64); // carry
            __uint120_product[i+j] = __uint120_product[i+j] << 64;
            __uint120_product[i+j] = __uint120_product[i+j] >> 64;
        }
    }

    for(size_t i=0; i<5; ++i) {
        product[i] = __uint120_product[4-i];
    }
}

int main() {

    unsigned long a[5] = { 0x53baaffed, 0x777fffeea, 0xffffffffffffffff, 0xfffffeee76543211, 0x0};
    unsigned long b[5] = { 86137123123, 96476846237467, 867122, 7778123919998798, 8277832};
    unsigned long c[5] = { 0, 0, 0, 0, 0};

    unsigned long correct[5] = {
        0x6ea59a213662e111, 0xfea04d6bc7e7d8bd, 0xc8e2e849a7d1be88, 0x32340a8b4d36ac05, 0xf3869b5d90c95937
    };
    
    std::cout << "a = ";
    printHexU320(a);

    std::cout << "b = ";
    printHexU320(b);

    u320mul(a,b,c);

    std::cout << "c = ";
    printHexU320(c);

    for(size_t i=0; i<5; ++i) {
        if(c[i] != correct[i]) {
            std::cout << "Incorrect Product\n";
            std::cout << "out   c[" << i << "] = ";
            printf("%016lx\n",c[i]);
            std::cout << "correct[" << i << "] = ";
            printf("%016lx\n",correct[i]);
            return 1;
        }
    }

    std::cout << "Correct Product\n";
    return 0;
}
