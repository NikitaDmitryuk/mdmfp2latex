#ifndef FILE_HPP
#define FILE_HPP

#include <string>
#include <fstream>
#include <sstream>

class File{
    public:
        virtual ~File()=0;
        virtual void convert(std::string flags)=0;
        virtual void readFile(std::string fileName)=0;
        std::string getMarkdownText();
        std::string getLatexText();
    protected:
        std::string _textLatex;
        std::string _textMarkdown;
        std::string _fileName;
};

#endif // FILE_HPP
