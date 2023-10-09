#include <iostream>

void increment1(int& num) {
    
    asm volatile (
        "mov %1, %0\n"
        "add $1, %0\n"
        : "=r" (num)
        : "r" (num)
    );
}

void increment2(int& num) {

    asm volatile (
        "add $1, %0"
        :"=m"(num)
    );
}



int main(){
    int one = 7;
    std::cout << one << "\n";
    increment1(one);
    std::cout << one << "\n";
    increment2(one);
    std::cout << one << "\n";
    increment1(one);
    std::cout << one << "\n";
    increment2(one);
    std::cout << one << "\n";
}