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
        mdFile.setPathToFile(_srcPath);
        mdFile.setFullFileName(_srcPath, mdFileName);

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
        _markdownFiles[i].readFile();
    }
}

void Document::setSrcPath(std::string srcPath){
    _srcPath = srcPath;
}

void Document::convertMdFiles(){
    for(int i = 0; i < _markdownFiles.size(); i++){
        _latexText.push_back(_markdownFiles[i].convert());
    }
}

std::vector<std::string> Document::getLatexText(){
    return _latexText;
}

void Document::createDocument(){
    for(auto text : _latexText){
        _documentText += text;
    }
}

void Document::createPreamble(){
    std::string fullDocumentTextMd;
    for(MdFile file : _markdownFiles){
        fullDocumentTextMd += file.getFileText();
    }
    std::ofstream outMdFile("preamble.md");
    outMdFile << fullDocumentTextMd;
    outMdFile.close();
    std::cout << "1" << std::endl;

    namespace bp = boost::process;
    bp::ipstream out;
    std::stringstream buffer;
    bp::child c("pandoc -s -f markdown -t latex preamble.md", bp::std_out > out);
    buffer << out.rdbuf();
    std::string textLatex = buffer.str();
    c.terminate();
    std::cout << "2" << std::endl;

    std::regex documentText("\\\\begin\\{document\\}([\\s\\S]*)\\\\end\\{document\\}");
    textLatex = std::regex_replace(textLatex, documentText, "%");
    std::cout << "3" << std::endl;

    namespace fs = std::filesystem;
    fs::path dir (".");
    fs::path file ("preamble.tex");
    fs::path full_path = dir / file;
    std::ofstream preambleFile(full_path.c_str());
    std::cout << full_path.c_str() << std::endl;
    preambleFile << textLatex;
    preambleFile.close();
}
