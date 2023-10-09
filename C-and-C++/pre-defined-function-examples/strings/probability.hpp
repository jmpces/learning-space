#ifndef PROBABILITY_HPP
#define PROBABILITY_HPP

#include <iostream>
#include "../math/basic_math_algo.hpp"

namespace probability
{
    std::string get_erased_index(const std::string& base_str, size_t index)
    {
        std::string erased_index = base_str;
        erased_index.erase(erased_index.begin()+index);
        return erased_index;
    }

    void combinations_internal(std::string char_set)
    {
        if(char_set.size()==1) return;
        std::cout<<char_set<<std::endl;
        for(size_t i=0; i<char_set.size(); ++i)
        {
            combinations_internal(get_erased_index(char_set,i));
        }
    }

    void combinations_main(std::string char_set)
    {
        combinations_internal(char_set);
        for(size_t i=0; i<char_set.size(); ++i) std::cout<<char_set[i]<<std::endl;
    }
}

#endif