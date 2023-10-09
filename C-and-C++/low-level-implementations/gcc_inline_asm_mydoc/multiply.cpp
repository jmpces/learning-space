#include <iostream>
#include <bitset>

void mul(unsigned int a, unsigned int b) {

    unsigned long p = (unsigned long)a * (unsigned long)b;
    std::cout << std::bitset<64>(p) << "\n";
}

void asm_mul(unsigned int a, unsigned int b) {

    unsigned int msb, lsb;

    asm volatile(
        "mov %2, %%eax\n\t"
        "mul %3\n\t"
        "mov %%edx, %0\n\t"
        "mov %%eax, %1"
        : "=r"(msb), "=r"(lsb) // on registers
        : "r"(a), "r"(b)
        : "rax", "rdx"
    );

    std::cout << std::bitset<32>(msb);
    std::cout << std::bitset<32>(lsb) << "\n";
}

void asm_mul2(unsigned int a, unsigned int b) {

    unsigned int msb, lsb;

    asm volatile(
        "mov %2, %%eax\n\t"
        "mul %3\n\t"
        "mov %%edx, %0\n\t"
        "mov %%eax, %1"
        : "=m"(msb), "=m"(lsb) // in memory, meaning you cannot use this operands for assembly instruction that only operates on registers
        : "r"(a), "r"(b)
        : "rax", "rdx"
    );

    std::cout << std::bitset<32>(msb);
    std::cout << std::bitset<32>(lsb) << "\n";
}

void asm_mul3(unsigned int a, unsigned int b) {

    unsigned int msb, lsb;

    // using asmSymbolicName instead of zero-base indexing
    asm volatile(
        "mov %[a_input], %%eax\n\t"
        "mul %[B_INPUT]\n\t"
        "mov %%edx, %[MSB]\n\t"
        "mov %%eax, %[lsb]"
        : [MSB]"=m"(msb), [lsb]"=m"(lsb)
        : [a_input]"r"(a), [B_INPUT]"r"(b)
        : "rax", "rdx"
    );

    std::cout << std::bitset<32>(msb);
    std::cout << std::bitset<32>(lsb) << "\n";
}

void asm_mul4(unsigned int a, unsigned int b) {

    unsigned long product;

    // using asmSymbolicName instead of zero-base indexing
    asm volatile(
        "mov %[a_input], %%eax\n\t"
        "mul %[B_INPUT]\n\t"
        "mov %%rdx, %[product]\n\t"
        "shl $32, %[product]\n\t" //note here that if we used "=m" for our product output, it won't compile since we cannot use the shift left 'shl' instruction on a memory operand
        "xor %%rax, %[product]"
        : [product]"=r"(product)
        : [a_input]"r"(a), [B_INPUT]"r"(b)
        : "rax", "rdx"
    );

    std::cout << std::bitset<64>(product) << "\n";
}

int main() {
    mul(4294967290, 4294967290);
    asm_mul(4294967290, 4294967290);
    asm_mul2(4294967290, 4294967290);
    asm_mul3(4294967290, 4294967290);
    asm_mul4(4294967290, 4294967290);
    return 0;
}