#ifndef READER_HPP
#define READER_HPP

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdio>
#include <cerrno>

namespace read
{
    std::string read_all(const std::string& sourcefile,int line_err, const std::string& filename)
    {
        std::FILE *filereader = std::fopen(filename.c_str(), "rb");
        if (filereader)
        {
            std::string filetext;
            std::fseek(filereader, 0, SEEK_END);
            filetext.resize(std::ftell(filereader));
            std::rewind(filereader);
            std::fread(&filetext[0], 1, filetext.size(), filereader);
            std::fclose(filereader);
            return(filetext);
        }
        std::cerr<<"\nERROR in line:"<<line_err<<" of '"<<sourcefile<<"'\nthe file '"<<filename
        <<"' was not found/cannot be read..."<<std::endl;
        exit(2);
    }
    ///@arg - 1st argument : takes a filename of file as a 'const char*'
    ///@returns - a 'string' content of the file
    #define all(filename) read_all(__FILE__,__LINE__,filename)

    std::vector<std::string> read_lines(const std::string& sourcefile, int line_err, const std::string& filename)
    {
        std::ifstream filereader;
        filereader.open(filename.c_str());

        if(filereader.fail()){
            std::cerr<<"\nERROR in line:"<<line_err<<" of '"<<sourcefile<<"'\nthe file '"<<filename
            <<"' was not found/cannot be read..."<<std::endl;
            exit(2);
        }

        std::vector<std::string> strlines;
        std::string tmp;
        while(!filereader.eof()){
            getline(filereader,tmp);
            strlines.push_back(tmp);
        }
        filereader.close();
        return strlines;
    }
    ///@arg - 1st argument : takes a filename of file as a 'const char*'
    ///@returns - a 'vector<string>' that contains the content of the file line by line
    #define lines(filename) read_lines(__FILE__,__LINE__,filename)

    std::vector<std::string> read_words(const std::string& sourcefile, int line_err, const std::string& filename, char word_separator){
        std::FILE *filereader = std::fopen(filename.c_str(), "rb");
        if (filereader)
        {
            std::vector<std::string> result_words;
            std::string filetext;
            std::fseek(filereader, 0, SEEK_END);
            filetext.resize(std::ftell(filereader));
            std::rewind(filereader);
            std::fread(&filetext[0], 1, filetext.size(), filereader);
            std::fclose(filereader);
            filetext = filetext + word_separator;

            bool start = false;
            size_t startwi, endwi;
            size_t str_size = filetext.size();

            for(size_t i=0; i<str_size; ++i){
                if(filetext[i]!=word_separator && !start)
                {
                    startwi = i;
                    start = true;
                }
                else if(filetext[i]==word_separator && start)
                {
                    endwi = i-startwi;
                    result_words.push_back(filetext.substr(startwi,endwi));
                    start = false;
                }
            }
            return result_words;
        }
        std::cerr<<"\nERROR in line:"<<line_err<<" of '"<<sourcefile<<"'\nthe file '"<<filename
        <<"' was not found/cannot be read..."<<std::endl;
        exit(2);
    }
    ///@arg - 1st argument : takes a filename of file as a 'const char*'
    ///@arg - 2nd argument : takes a word separator as a 'char'
    ///@returns - a 'vector<string>' that contains the content of the file word by word
    #define words(filename,word_separator) read_words(__FILE__,__LINE__,filename,word_separator)
    
    /// returns the values of given variables from an file
    /// @param 1 : .env filename
    /// @param 2 : variables
    /// @param 3 : separator or assignment used in the env file
    std::vector<std::string> env_raw(const std::string& sourcefile, int line_err, const std::string& envfile, const std::vector<std::string>& variables, std::string sep="=")
    {
        std::string filetext;

        std::FILE *filereader = std::fopen(envfile.c_str(), "rb");
        if (filereader)
        {
            std::fseek(filereader, 0, SEEK_END);
            filetext.resize(std::ftell(filereader));
            std::rewind(filereader);
            std::fread(&filetext[0], 1, filetext.size(), filereader);
            std::fclose(filereader);
        }
        else
        {
            std::cerr<<"\nERROR in line:"<<line_err<<" of '"<<sourcefile<<"'\nthe file '"<<filename
            <<"' was not found/cannot be read..."<<std::endl;
            exit(2);
        }

        std::vector<std::string> values;

        for(size_t i=0; i<variables.size(); ++i)
        {
            std::regex regexp(variables[i]+sep+"\\S+");
            std::smatch match;

            if(std::regex_search(filetext,match,regexp))
            {
                std::string value = match[0];
                value.erase(0,variables[i].size()+sep.size());
                values.push_back(value);
            }
            else
            {
                std::cerr<<"\nERROR in line:"<<line_err<<" of '"<<sourcefile<<"'\nthe file '"<<filename
                <<"' has no variable '"<<variables[i]<<"'"<<std::endl;
                exit(2);
            }
        }
        #define env(filename,variable) env_raw(__FILE__,__LINE__,filename,variable)
        #define env(filename,variable,word_separator) env_raw(__FILE__,__LINE__,filename,variable,word_separator)

        return values;
    }
}

#endif
