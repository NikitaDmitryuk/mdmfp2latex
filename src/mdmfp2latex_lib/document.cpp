#include "mdmfp2latex/document.hpp"

Document::Document(std::string documentName){
    _documentName = documentName;
}

void Document::setDocumentStruct(std::string structFile){
    namespace fs = std::filesystem;
    fs::path dir (_srcPath);
    fs::path file (structFile);
    fs::path full_path = dir / file;
    std::ifstream infile(full_path.c_str());
    std::string line;

    while (std::getline(infile, line))
    {
        std::vector<std::string> strs;
        std::vector<std::string> properties;
        
        int indent = line.find_first_not_of(' ') / 4;

        boost::split(strs, line, boost::is_any_of(":"));
        std::string mdFileName = strs[0];
        boost::erase_all(mdFileName, " ");

        std::string propertiesString = strs[1];
        boost::split(properties, propertiesString, boost::is_any_of(" "));

        MdFile mdFile = MdFile(mdFileName);
        mdFile.setProperties(properties);
        mdFile.setFileNestingLevel(indent);

        _markdownFiles.push_back(mdFile);
    }
}

std::string Document::getDocumentName(){
    return _documentName;
}

std::string Document::getDocumentText(){
    return _documentText;
}

std::vector<MdFile> Document::getMarkdownFiles(){
    return _markdownFiles;
}

void Document::readMdFiles(){
    for(int i = 0; i < _markdownFiles.size(); i++){
        _markdownFiles[i].readFile(_srcPath);
    }
}

void Document::setSrcPath(std::string srcPath){
    _srcPath = srcPath;
}
