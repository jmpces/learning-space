#ifndef INT_ENDIAN_SWAPS_HPP
#define INT_ENDIAN_SWAPS_HPP

#include <iostream>
#include <stdint.h>

/// swap endianness for short
short swap_endian_int16(short number) 
{
    return (number << 8) | ((number >> 8) & 0xFF);
}

/// swap endianness for unsigned short
unsigned short swap_endian_uint16(unsigned short number) 
{
    return (number << 8) | (number >> 8);
}

/// swap endianness for int
int swap_endian_int32(int number)
{
    number = ((number << 8) & 0xFF00FF00) | ((number >> 8) & 0xFF00FF); 
    return (number << 16) | ((number >> 16) & 0xFFFF);
}

/// swap endianness for unsigned int
unsigned int swap_endian_uint32(unsigned int number)
{
    number = ((number << 8) & 0xFF00FF00) | ((number >> 8) & 0xFF00FF); 
    return (number << 16) | (number >> 16);
}

/// swap endianness of long int
long int swap_endian_int64(long int number)
{
    number = ((number << 8) & 0xFF00FF00FF00FF00ULL) | ((number >> 8) & 0x00FF00FF00FF00FFULL);
    number = ((number << 16) & 0xFFFF0000FFFF0000ULL) | ((number >> 16) & 0x0000FFFF0000FFFFULL);
    return (number << 32) | ((number >> 32) & 0xFFFFFFFFULL);
}

/// swap endianness of unsigned long int
unsigned long int swap_endian_uint64(unsigned long int number)
{
    number = ((number << 8) & 0xFF00FF00FF00FF00ULL) | ((number >> 8) & 0x00FF00FF00FF00FFULL);
    number = ((number << 16) & 0xFFFF0000FFFF0000ULL) | ((number >> 16) & 0x0000FFFF0000FFFFULL);
    return (number << 32) | (number >> 32);
}

#endif