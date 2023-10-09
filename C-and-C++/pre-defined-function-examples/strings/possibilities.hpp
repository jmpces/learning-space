#ifndef POSSIBILITIES_HPP
#define POSSIBILITIES_HPP

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <limits>
#include <unordered_map>
#include "../math/basic_math_algo.hpp"

namespace possibilities
{
    static std::string default_char_set = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+[]\\{}|;\':\",./<>?";

    class collection
    {
        private:

            std::string collection_elements = "";
            std::unordered_map<long long,char> int_to_char;
            std::unordered_map<char,long long> char_to_int;
            
        public:

            collection()
            {
                size_t char_set_size = default_char_set.size();
                for(size_t i=0; i<char_set_size; ++i)
                {
                    int_to_char[i] = default_char_set[i];
                    char_to_int[default_char_set[i]] = i;
                }
                collection_elements.push_back(default_char_set[0]);
            }

            collection(const std::string& costum_char_set)
            {
                size_t char_set_size = costum_char_set.size();
                for(size_t i=0; i<char_set_size; ++i)
                {
                    if(char_to_int.find(costum_char_set[i]) == char_to_int.end()){
                        char_to_int[costum_char_set[i]] = i;
                    }
                    else{
                        std::cout<<"ERROR : possibilities::collection - there should be no similar characters"<<std::endl;
                        exit(2);
                    }
                        int_to_char[i] = costum_char_set[i];
                }
                collection_elements.push_back(costum_char_set[0]);
            }

            collection(const char* costum_char_set_char)
            {
                std::string costum_char_set(costum_char_set_char);
                
                size_t char_set_size = costum_char_set.size();
                for(size_t i=0; i<char_set_size; ++i)
                {
                    if(char_to_int.find(costum_char_set[i]) == char_to_int.end()){
                        char_to_int[costum_char_set[i]] = i;
                    }
                    else{
                        std::cout<<"ERROR : possibilities::collection - there should be no similar characters"<<std::endl;
                        exit(2);
                    }
                        int_to_char[i] = costum_char_set[i];
                } 
                collection_elements.push_back(costum_char_set[0]);
            }

            void set_collection_elements(std::string collection_state)
            {
                collection_elements = collection_state;
            }

            std::string value(){
                return collection_elements;
            }

            inline void next()
            {
                size_t char_set_size = int_to_char.size();
                size_t collection_size = collection_elements.size();

                long long current_char_value;
                size_t i;
            
                for(i=0; i<collection_size; ++i)
                {
                    current_char_value =  char_to_int[collection_elements[i]];
                    current_char_value++;

                    if(current_char_value>=char_set_size && (i==collection_size-1))
                    {
                        collection_elements[i] = int_to_char[0];
                        collection_elements.push_back(int_to_char[0]);
                        break;
                    }
                    else if(current_char_value>=char_set_size)
                    {
                        collection_elements[i] = int_to_char[0];
                    }
                    else
                    {
                        collection_elements[i] = int_to_char[current_char_value];
                        break;
                    }
                }
            }

            inline void prev()
            {
                size_t char_set_size = int_to_char.size();
                size_t collection_size = collection_elements.size();

                long long current_char_value;
                size_t i;

                for(i=0; i<collection_size; ++i)
                {
                    current_char_value = char_to_int[collection_elements[i]];
                    current_char_value--;

                    if(current_char_value>=0)
                    {
                        collection_elements[i] = int_to_char[current_char_value];
                        break;
                    }
                    else if(current_char_value<0 && (i==collection_size-1))
                    {
                        collection_elements.erase(collection_elements.end()-1);
                        break;
                    }
                    else if(current_char_value<0)
                    {
                        collection_elements[i] = int_to_char[char_set_size-1];
                    }
                }
            }
    };
}

#endif