#ifndef TRANSFORM_HPP
#define TRANSFORM_HPP

#include <iostream>

namespace transform
{
    std::string tolower(const std::string& str)
    {
        std::string newstr = str;
        size_t length = str.size();
        while(length){
            length--;
            newstr[length] = (char)std::tolower(newstr[length]);
        }
        return newstr;
    }

    std::string toupper(const std::string& str)
    {
        std::string newstr = str;
        size_t length = str.size();
        while(length){
            length--;
            newstr[length] = (char)std::toupper(newstr[length]);
        }
        return newstr;
    }

    std::string replace_all(const std::string& mainstr, const std::string& substr, const std::string& new_substr)
    {
        std::string newstr = mainstr;
        size_t length = newstr.size();
        size_t slen   = substr.size();
        size_t rlen   = new_substr.size();

        for(size_t i=0; i<length; ++i)
        {
            if(newstr[i]==substr[0])
            {
                bool match = true;
                for(size_t j=0; j<slen; ++j)
                {
                    if(newstr[i+j]!=substr[j])
                    {
                        match = false;
                        break;
                    }
                }

                if(match)
                {
                    newstr.replace(i,slen,new_substr);
                    length = newstr.size();
                    i+=rlen;
                }
            }
        }
        return newstr;
    }
}

#endif