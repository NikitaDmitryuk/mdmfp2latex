#include "mdmfp2latex/parser.hpp"

Parser::Parser() = default;
Parser::~Parser() = default;

void Parser::parseFrame(std::string filename){
    std::ifstream infile(filename);
    std::string line;
    while (std::getline(infile, line))
    {
        infoStruct item;
        std::vector<std::string> strs;
        std::vector<std::string> properties;
        int indent = line.find_first_not_of(' ') / 4;
        item.numOfTab = indent;
        boost::split(strs, line, boost::is_any_of(":"));
        std::string mdFilename = strs[0];
        boost::erase_all(mdFilename, " ");
        item.filename = mdFilename;
        std::string propertiesString = strs[1];
        boost::split(properties, propertiesString, boost::is_any_of(" "));
        item.properties = properties;
        fileStruct.push_back(item);
    }
}
