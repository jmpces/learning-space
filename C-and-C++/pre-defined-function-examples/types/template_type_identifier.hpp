#ifndef TEMPLATE_TYPE_IDENTIFIER_HPP
#define TEMPLATE_TYPE_IDENTIFIER_HPP

#include <iostream>
#include <type_traits>

/// type identifier for template types
enum dtype_name {
    SHORT,
    INT,
    LONG,
    #if(__SIZEOF_LONG_LONG__!=__SIZEOF_LONG__)
    LLONG,
    #endif
    FLOAT,
    DOUBLE,
    LDOUBLE,
    NOT_A_TYPE=-1
};

/// signedness type identifier for template types
enum signedness {
    /// value range from 0 to n>0 only positive values
    UNSIGNED,
    /// value range from negative to positive values 
    SIGNED,
    /// no signedness a type pointer or, could be a user defined data type, class, struct, etc.
    NO_SIGNEDNESS
};

/// NOTE: in some sytems the , long and long long might have the same byte size, if that is the case passing long long to the template will return a dtype::LONG only
template<typename T>
dtype_name check_type()
{
    size_t byte_size = sizeof(T);
    if(std::is_integral<T>::value)
    {
        switch (byte_size)
        {
            case __SIZEOF_SHORT__: return dtype_name::SHORT;
            case __SIZEOF_INT__: return dtype_name::INT;
            case __SIZEOF_LONG__: return dtype_name::LONG;
            #if(__SIZEOF_LONG_LONG__!=__SIZEOF_LONG__)
            case __SIZEOF_LONG_LONG__: return dtype_name::LLONG;
            #endif
            default: return dtype_name::NOT_A_TYPE;
        }
    }
    else if(std::is_floating_point<T>::value)
    {
        switch (byte_size)
        {
            case __SIZEOF_FLOAT__: return dtype_name::FLOAT;
            case __SIZEOF_DOUBLE__: return dtype_name::DOUBLE;
            case __SIZEOF_LONG_DOUBLE__: return dtype_name::LDOUBLE;
            default: return dtype_name::NOT_A_TYPE;
        }
    }
    else
    {
        return dtype_name::NOT_A_TYPE;
    }
}

template<typename T>
signedness check_signedness()
{
    if(std::is_signed<T>::value) return signedness::SIGNED;
    else if(std::is_unsigned<T>::value) return signedness::UNSIGNED;
    return signedness::NO_SIGNEDNESS;
}

template<typename T>
void display_type()
{
    if(check_signedness<T>()==signedness::UNSIGNED)
    {
        std::cout<<"unsigned ";
    }
    else if(check_type<T>()==dtype_name::SHORT)
    {
        std::cout<<"short\n";
    }
    else if(check_type<T>()==dtype_name::INT)
    {
        std::cout<<"int\n";
    }
    else if(check_type<T>()==dtype_name::LONG)
    {
        std::cout<<"long\n";
    }
    else if(check_type<T>()==dtype_name::FLOAT)
    {
        std::cout<<"float\n";
    else if(check_type<T>()==dtype_name::DOUBLE)
    {
        std::cout<<"double\n";
    }
    else if(check_type<T>()==dtype_name::LDOUBLE)
    {
        std::cout<<"long double\n";
    }
}

#endif