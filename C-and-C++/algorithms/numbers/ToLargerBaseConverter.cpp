#include <iostream>
#include <vector>

#define PRINT_NUMBER(num,basename, baseformat) \
    std::cout << basename << " : "; \
    for(auto h : num) { \
        printf(baseformat,h); \
    } \
    std::cout << "\n";

std::vector<uint8_t> toLargerBase(std::string input, size_t input_base, size_t output_base) {
    std::vector<uint8_t> output(input.size(),0);

    for(size_t i=0; i<input.size(); ++i) {
        uint8_t carry = input[i] - '0';
        size_t j=input.size();
        while(j--) {
            uint8_t tmp = output[j] * input_base + carry;
            output[j] = tmp % output_base;
            carry = tmp / output_base;
        }
    }

    size_t leading_zeros = 0;
    while(output.size()>1 && !output[leading_zeros])
        leading_zeros++;

    output.erase(output.begin(),output.begin()+leading_zeros);

    return output;
}

int main() {

    std::string base2 =
        "11100010100111101001111111001110001111001010001110010111"
        "01001111010010001010101010010100111111000001110000001000"
        "11111111111110000000000000000000000000011111111111111111";
    
    std::vector<uint8_t> octarray = toLargerBase(base2,2,8);
    std::vector<uint8_t> decarray = toLargerBase(base2,2,10);
    std::vector<uint8_t> hexarray = toLargerBase(base2,2,16);

    std::cout << "bin : " << base2 << "\n\n";
    PRINT_NUMBER(octarray,"oct","%o");
    PRINT_NUMBER(decarray,"dec","%d");
    PRINT_NUMBER(hexarray,"hex","%x");
}
