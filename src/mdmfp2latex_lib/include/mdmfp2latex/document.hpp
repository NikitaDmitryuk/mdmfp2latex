#ifndef DOCUMENT_HPP
#define DOCUMENT_HPP

#include <string>
#include <vector>
#include <boost/algorithm/string.hpp>
#include <mdmfp2latex/mdfile.hpp>
#include <filesystem>

class Document{
    public:
        Document(std::string documentName);
        void setDocumentStruct(std::string structFile);
        void readMdFiles();
        std::string getDocumentName();
        std::string getDocumentText();
        std::vector<MdFile> getMarkdownFiles();
        void setSrcPath(std::string);
    
    private:
        std::string _documentName;
        std::string _documentText;
        std::vector<MdFile> _markdownFiles;
        std::string _srcPath;
};

#endif // DOCUMENT_HPP
