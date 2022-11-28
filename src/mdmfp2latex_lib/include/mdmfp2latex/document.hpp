#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <mdmfp2latex/mdfile.hpp>
#include <filesystem>
#include <iostream>
#include "boost/process.hpp"
#include <sstream>

class Document{
    public:
        Document(std::string documentName);
        void setDocumentStruct(std::string structFile);
        void readMdFiles();
        std::string getDocumentName();
        std::string getDocumentText();
        std::vector<MdFile> getMarkdownFiles();
        void setSrcPath(std::string);
        void convertMdFiles();
        std::vector<std::string> getLatexText();
        void createDocument();
        void createPreamble();
    
    private:
        std::string _documentName;
        std::string _documentText;
        std::vector<std::string> _latexText;
        std::vector<MdFile> _markdownFiles;
        std::string _srcPath;
        std::string _outputPath;
        std::string _preamble;
};

#endif // DOCUMENT_HPP
