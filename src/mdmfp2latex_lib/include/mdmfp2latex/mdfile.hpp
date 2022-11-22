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
        std::string convert(std::string flags = "");
        void readFile();
        void setProperties(std::vector<std::string> properties);
        void setFileNestingLevel(int n);
        std::string getFileName();
        int getFileNestingLevel();
        std::string getFileText();
        std::vector<std::string> getProperties();
        void setPathToFile(std::string pathToFile);
        void setFullFileName(std::string path, std::string fileName);
        std::string getFullFileName();
        std::string headerReplacement(std::string text);

    private:
        std::string _fileName;
        int _fileNestingLevel;
        std::string _fileText;
        std::string _pathToFile;
        std::string _fullFileName;
        std::vector<std::string> _properties;
};

#endif // MDFILE_HPP
