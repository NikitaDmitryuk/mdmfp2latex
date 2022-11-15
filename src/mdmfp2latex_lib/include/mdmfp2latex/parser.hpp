#ifndef PARSER_HPP
#define PARSER_HPP

#include <fstream>
#include <string>
#include <sstream>
#include <iostream>
#include <map>
#include <vector>
#include <boost/algorithm/string.hpp>

class Parser{
    public:
        Parser();
        ~Parser();
        struct infoStruct
        {
            std::string filename;
            int numOfTab;
            std::vector<std::string> properties;
        };
        void parseFrame(std::string fileName);
        infoStruct getInfoStruct();

    private:
        std::vector<infoStruct> fileStruct;
        size_t split(const std::string &txt, std::vector<std::string> &strs, char ch);
};

#endif // PARSER_HPP
