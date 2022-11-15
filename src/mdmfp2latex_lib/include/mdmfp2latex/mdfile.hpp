#ifndef MDFILE_HPP
#define MDFILE_HPP

#include "file.hpp"

class MdFile: public File{
    public:
        MdFile();
        ~MdFile();
        void convert(std::string flags);
        void readFile(std::string fileName);
};

#endif // MDFILE_HPP
