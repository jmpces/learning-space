#ifndef WRITER_HPP
#define WRITER_HPP

#include <iostream>
#include <fstream>

namespace write
{
    ///@arg - takes a const char* filename and create that file where you can write on
    void create(const std::string& filename)
    {
        std::ofstream file;
        file.open(filename);
        file.close();
    }

    void append_string(std::string sourcefile, int line_err,const std::string& filename, const std::string& towrite)
    {
        std::ifstream readf;
        readf.open(filename);

        if(readf.fail()){
            std::cerr<<"\nERROR in line:"<<line_err<<" of '"<<sourcefile<<"'\nthe file '"<<filename
            <<"' was not found/unable to write..."<<std::endl;
            exit(2);
        }

        std::ofstream outfile;
        outfile.open(filename,std::ios_base::app);
        outfile<<towrite;
        outfile.close();
    }
    ///@arg - 1st argument : takes a filename of file as a 'const char*'
    ///@arg - 2nd argument : takes a string message to write append on the filename
    #define append(filename,towrite) append_string(__FILE__,__LINE__,filename,towrite)

    void overwrite_string(std::string sourcefile, int line_err,const std::string& filename, const std::string& towrite)
    {
        std::ifstream readf;
        readf.open(filename);

        if(readf.fail()){
            std::cerr<<"\nERROR in line:"<<line_err<<" of '"<<sourcefile<<"'\nthe file '"<<filename
            <<"' was not found/unable to write..."<<std::endl;
            exit(2);
        }

        std::ofstream outfile;
        outfile.open(filename,std::ios_base::trunc);
        outfile<<towrite;
        outfile.close();
    }
    ///@arg - 1st argument : takes a filename of file as a 'const char*'
    ///@arg - 2nd argument : takes a string message to overite the content of the filename
    #define overwrite(filename,towrite) overwrite_string(__FILE__,__LINE__,filename,towrite)

}

#endif
