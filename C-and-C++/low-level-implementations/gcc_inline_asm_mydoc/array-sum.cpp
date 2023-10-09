#include <iostream>
#include <chrono>

uint64_t sum_cpp(const uint64_t *numbers, size_t length) {
    uint64_t sum = 0;
    for(size_t i=0; i<length; ++i) {
        sum += numbers[i];
    }
    return sum;
}

uint64_t sum_asm(const uint64_t *numbers, size_t length) {
    uint64_t sum = 0;
    asm(
        "xorq %%rax, %%rax\n\t"
        "%=:\n\t" // <-- let the compiler generate a unique label for us.

        "addq (%[numbers], %%rax, 8), %[sum]\n\t"
        "incq %%rax\n\t"

        "cmpq %%rax, %[length]\n\t"
        "jne %=b\n\t" // <-- jumps back to the previous label, use "f" for forward jumps.
        :
        [sum]"+r"(sum)
        :
        [numbers]"r"(numbers),
        [length]"r"(length) // note : using "c" means we are putting the value inside the C registers, rcx, ecx etc.
        :
        "%rax","cc"
    );
    return sum;
}

int main() {

    size_t length = 99999999;

    uint64_t *arr = new uint64_t[length];
    uint64_t cpp_total = 0;
    uint64_t asm_total = 0;

    for(size_t i=1; i<=length; ++i) arr[i] = i*5;

    for(size_t i=0; i<5; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        cpp_total = sum_cpp(arr,length);
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
        std::cout << "cpp time : " << dur.count() << " nanoseconds\n";
    }
    std::cout << "\n";

    for(size_t i=0; i<5; ++i) {
        auto start = std::chrono::high_resolution_clock::now();
        asm_total = sum_asm(arr,length);
        auto end = std::chrono::high_resolution_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::nanoseconds>(end-start);
        std::cout << "asm time : " << dur.count() << " nanoseconds\n";
    }
    std::cout << "\n";

    std::cout << "cpp sum = " << cpp_total << "\n";
    std::cout << "asm sum = " << asm_total << "\n";

    delete [] arr;

    return 0;
}

/* WORKING EXAMPLE 2
int main() {

    uint64_t odds[5] = {1,3,5,7,9};
    uint64_t sum = 10;

    asm(
        "xorq %[sum], %[sum]\n\t"
        "movq $0, %%rax\n\t" // index register
        
        // 8 is the scale factor, or the size of the element of the array
        // since in our case we use a uint64_t which have 8 bytes, hence
        // we use 8 for our scale factor
        "addq (%[odds], %%rax, 8), %[sum]\n\t"
        
        "incq %%rax\n\t" // increment the index register to move to the next index
        "addq (%[odds], %%rax, 8), %[sum]\n\t"

        "incq %%rax\n\t"
        "addq (%[odds], %%rax, 8), %[sum]\n\t"

        "incq %%rax\n\t"
        "addq (%[odds], %%rax, 8), %[sum]\n\t"

        "incq %%rax\n\t"
        "addq (%[odds], %%rax, 8), %[sum]"
        
        // imagine it like this : addq (ptr + (index * sizeof(uint64_t))), %[sum]
        :
        [sum]"+r"(sum)
        :
        [odds]"r"(odds) // load the array into the B register
        :
        "%rax"
    );

    std::cout << "sum = " << sum << "\n";

    return 0;
} //*/


/* WORKING EXAMPLE 3
#include <iostream>

int main() {

    uint64_t odds[5] = {1,3,5,7,9};
    uint64_t sum = 10;

    asm(
        "xorq %[sum], %[sum]\n\t"
        "movq $0, %%rax\n\t" // index register
        
        // 8 is the scale factor, or the size of the element of the array
        // since in our case we use a uint64_t which have 8 bytes, hence
        // we use 8 for our scale factor
        "addq (%%rbx, %%rax, 8), %[sum]\n\t"
        
        "incq %%rax\n\t" // increment the index register to move to the next index
        "addq (%%rbx, %%rax, 8), %[sum]\n\t"

        "incq %%rax\n\t"
        "addq (%%rbx, %%rax, 8), %[sum]\n\t"

        "incq %%rax\n\t"
        "addq (%%rbx, %%rax, 8), %[sum]\n\t"

        "incq %%rax\n\t"
        "addq (%%rbx, %%rax, 8), %[sum]\n\t"
        :
        [sum]"+r"(sum)
        :
        "b"(odds) // load the array into the B register
        :
        "%rax"
    );

    std::cout << "sum = " << sum << "\n";

    return 0;
}
//*/
