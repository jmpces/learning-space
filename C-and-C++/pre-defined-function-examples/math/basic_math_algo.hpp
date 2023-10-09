#ifndef BASIC_MATH_ALGO
#define BASIC_MATH_ALGO

#include <iostream>
#include <cmath>

namespace calculate
{
    /// @returns factorial - combinations
    unsigned long long int naive_factorial(unsigned long long int n)
    {
        if(n>20)
        {
            std::cerr<<"\n\nERROR : naive_factorial("<<n<<")\n\tfactorial number to large for type:'unsigned long long int' to hold.\n";
            std::cerr<<"\tvalid range are 0-20 only\n";
            exit(1);
        }
        else if(n<0)
        {
            std::cerr<<"\n\nERROR : naive_factorial("<<n<<")\n\tnumber must be greater than or equal to zero.\n";
            std::cerr<<"\tvalid range are 0-20 only\n";
            exit(1);
        }
        unsigned long long int factorial = 1;
        for(size_t i=2; i<=n; ++i) factorial = i*factorial;
        return factorial;
    }

    /// @returns total possible combinations, @arg n - size of character set, @arg r - size of the resulting word
    unsigned long long int nCr(unsigned long long int n, unsigned long long int r)
    {
        return naive_factorial(n)/(naive_factorial(r)*naive_factorial(n-r));
    }

    /// @returns total possible permutations, @arg n - size of character set, @arg r - size of the resulting word
    unsigned long long int nPr(unsigned long long int n, unsigned long long int r)
    {
        return naive_factorial(n)/naive_factorial(n-r);
    }

    /// @returns total possible increments, @arg n - size of character set, @arg r - size of the resulting word
    unsigned long long int nIr(unsigned long long int n, unsigned long long int r)
    {
        return pow(n,r);
    }
}

#endif