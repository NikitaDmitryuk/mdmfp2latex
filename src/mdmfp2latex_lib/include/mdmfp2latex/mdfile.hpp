#ifndef MDFILE_HPP
#define MDFILE_HPP

#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include "boost/process.hpp"
#include <filesystem>
#include <regex>
#include <iterator>

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

    private:
        std::string downFileHeaders(std::string text);
        std::string linkReplacement(std::string text);
        std::string headerReplacement(std::string text);
        std::string hyperlinkReplacement(std::string text);
        std::string firstLinkReplacement(std::string text);
        std::string _fileName;
        int _fileNestingLevel;
        std::string _fileText;
        std::string _pathToFile;
        std::string _fullFileName;
        std::vector<std::string> _properties;
};

#endif // MDFILE_HPP
