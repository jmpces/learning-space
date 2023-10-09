#ifndef STLVEC_HPP
#define STLVEC_HPP

#include <iostream>
#include <vector>
#include <algorithm>

namespace vec
{
    template<typename T>
    std::vector<T> concat(const std::vector<T>& a, const std::vector<T>& b)
    {
        std::vector<T> c;
        c.reserve(a.size()+b.size());
        c.insert(c.end(),a.begin(),a.end());
        c.insert(c.end(),b.begin(),b.end());
        return c;
    }

    template<typename T>
    std::vector<T> subseq_raw(std::string sourcefile, size_t line_err, const std::vector<T>& a, size_t start, size_t length)
    {
        if(start+length>a.size() || start<0){
            std::cerr<<"\nERROR in line:"<<line_err<<" of '"<<sourcefile<<"'"<<std::endl
            <<"sub vector overflow..."<<std::endl;
            exit(2);
        }

        std::vector<T> b;
        b.reserve(length);
        b.insert(b.end(),a.begin()+start,a.begin()+start+length);
        return b;
    }
    #define subseq(a,start,length) subseq_raw(__FILE__,__LINE__,a,start,length)

    template<typename T>
    bool has_member(const std::vector<T>& a, T e)
    {
        if(std::find(a.begin(),a.end(),e)!=a.end())
            return true;
        return false;
    }
}

#endif