#ifndef LATEXFILE_HPP
#define LATEXFILE_HPP

#include "file.hpp"

class LatexFile: public File{
    public:
        LatexFile();
        ~LatexFile();
        void convert(std::string flags);
        void readFile(std::string fileName);
};

#endif // LATEXFILE_HPP
