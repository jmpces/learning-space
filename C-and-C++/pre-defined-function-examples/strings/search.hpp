#ifndef SEARCH_HPP
#define SEARCH_HPP

#include <iostream>
#include "transform.hpp"

namespace search
{
    bool pattern_s(const std::string& pattern, const std::string& subject)
    {
        size_t found = subject.find(pattern);
        if(found!=std::string::npos) return true;
        return false;
    }

    bool pattern_i(const std::string& pattern, const std::string& subject)
    {
        std::string new_pattern = transform::tolower(pattern);
        std::string new_subject = transform::tolower(subject);
        return pattern_s(new_subject,new_pattern);
    }
}

#endif