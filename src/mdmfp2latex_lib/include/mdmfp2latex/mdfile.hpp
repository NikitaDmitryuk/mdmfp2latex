#ifndef MDFILE_HPP
#define MDFILE_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "boost/process.hpp"
#include <filesystem>

#include <iostream>

class MdFile{
    public:
        MdFile(std::string fileName);
        ~MdFile();
        std::string convert(std::string flags);
        void readFile(std::string srcPath);
        void setProperties(std::vector<std::string> properties);
        void setFileNestingLevel(int n);
        std::string getFileName();
        int getFileNestingLevel();
        std::string getFileText();
        std::vector<std::string> getProperties();

    private:
        std::string _fileName;
        int _fileNestingLevel;
        std::string _fileText;
        std::vector<std::string> _properties;
};

#endif // MDFILE_HPP
