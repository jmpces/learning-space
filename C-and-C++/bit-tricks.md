### NUMBERS

#### Check if two numbers have opposite signs
```c++
if((num1^num2)<0) printf("opposite signs\n");
else              printf("same signs\n");
```

#### Check if the number is odd or even
```c++
if(num&1) cout << n << " is odd";
else      cout << n << " is even";
```

#### Flipping 1 to 0, and 0 to 1
```c++
unsigned int flip(unsigned int one_or_zero) {
    return one_or_zero ^ 1u;
}
```

#### Check if numbers in the range of 1 and 0 is not-equal
```c++
unsigned int not_equal(unsigned int one_or_zero_A, unsigned int one_or_zero_B) {
    return (one_or_zero_A ^ one_or_zero_B);
}
```

#### Check if numbers in the range of 1 and 0 is equal
To do this combine the previous two techniques of flipping 1 and 0, and using xor to check if two numbers is equal.

### LETTERS

#### Invert the case of a character (upper to lower and vice versa)
```c++
char(letter ^ ' ')
```

#### Find the position of a letter in alphabet (case irrelevant)
```c++
(letter & 31) // returns position 1
(letter & 31) // returns position 3
```

### INDEXING

#### NOTE: the following examples reads the bits from right to left
```
example : bit[N] bit[N-1] ... bit[1] bit[0]
```

#### Turning the K'th bit off (CLEAR)
```c++
int num = 55, i = 2; // 55 -> 00110111
num &= ~(1 << i);    // 51 -> 00110011
```

#### Turning the K'th bit on (SET)
```c++
int num = 51, i = 2; // 51 -> 00110011
num |= (1 << i);     // 55 -> 00110111
```

#### TOGGLE the K'th bit (turn it ON if it's OFF and vice-versa)
```c++
num ^= (1 << i);
```

#### Check if the K'th bit is SET/ON
```c++
int num = 430, i = 1;
//430 -> 10101110

bool ON = num&(1<<i)
// which in the case of 430, the 2nd bit is ON so the boolean is set to true
```

#### Display bits
```c++
#include <iostream>
#include <bitset>

#define BITS_IN_BYTE 8
#define BYTES_IN_INT sizeof(int)
#define INT_TOTAL_BITS BYTES_IN_INT*BITS_IN_BYTE

int main(){
    int num = 103;

    // display all bits
    std::cout << std::bitset<INT_TOTAL_BITS>(num) <<  "\n";

    // display the first 8 bits
    std::cout << std::bitset<8>(num) << "\n";
    return 0;
}
```

### Merge Bits
```c++
unsigned int method1(unsigned char byte4, unsigned char byte3, unsigned char byte2, unsigned char byte1)
{
    unsigned int num = 0;
    num = byte4;
    num <<=8u;
    num |= byte3;
    num <<=8u;
    num |= byte2;
    num <<=8u;
    num |= byte1;
    return num;
}

unsigned int method2(unsigned char byte4, unsigned char byte3, unsigned char byte2, unsigned char byte1)
{
    unsigned int num = 0, temp;
    temp = byte4;
    temp <<= 24u;
    num |= temp;
    temp = byte3;
    temp <<= 16u;
    num |= temp;
    temp = byte2;
    temp <<= 8u;
    num |= temp;
    temp = byte1;
    num |= temp;
    return num;
}

unsigned int method3(unsigned char byte4, unsigned char byte3, unsigned char byte2, unsigned char byte1)
{
    return (byte4 << 24u)|(byte3<<16u)|(byte2<<8u)|byte1;
}
```

### Split Bits
```c++
void split1(const uint32_t& main, uint8_t& byte4, uint8_t& byte3, uint8_t& byte2, uint8_t& byte1)
{
    byte1 = main;
    byte2 = main >> 8;
    byte3 = main >> 16;
    byte4 = main >> 24;
    // & 0xFF <- you might need to add this in some cases
    // ex: byteN = (main >> bits) & 0xFF
}
```
