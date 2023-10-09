#ifndef REMOVES_HPP
#define REMOVES_HPP

#include <iostream>
#include <algorithm>
#include <regex>

/// namespace for string remove operations, like remove a substring, set of characters & etc.
namespace removes
{
   /// inplace remove all matching characters given
   void match_(std::string &str, std::string characters)
   {
      for(unsigned int i = 0; i < characters.size(); ++i)
      {
         str.erase(std::remove(str.begin(), str.end(), characters[i]), str.end() );
      }
   }

   /// returns a string where all matching characters given is removed
   std::string match(std::string str, std::string characters)
   {
      for(unsigned int i = 0; i < characters.size(); ++i)
      {
         str.erase(std::remove(str.begin(), str.end(), characters[i]), str.end() );
      }
      return str;
   }

   /// returns a string where all characters that is enclosed/between two given characters are removed
   std::string between(const std::string& str, char front, char back)
   {
      std::string set = "[   ]", enclosed = ".+";
      set[1] = front;
      set[2] = back;

      std::regex regexp(set+enclosed+set); // [frontback].+[frontback]
      std::regex regemp(set+set);          // [frontback][frontback]

      // 1. removes characters enclosed inside or between the sets
      // 2. removes empty sets 
      return std::regex_replace(std::regex_replace(str,regexp,""),regemp,"");
   }
}

#endif