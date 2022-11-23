#include "mdmfp2latex/mdfile.hpp"

MdFile::MdFile(std::string fileName){
    _fileName = fileName;
}

MdFile::~MdFile() = default;

std::string MdFile::convert(std::string flags){
    namespace bp = boost::process;
    bp::ipstream out;
    std::stringstream buffer;
    bp::child c("pandoc -f markdown -t latex " + flags + " " + _fullFileName, bp::std_out > out);
    buffer << out.rdbuf();
    std::string _textLatex = buffer.str();
    c.terminate();
    _textLatex = headerReplacement(_textLatex);
    _textLatex = linkReplacement(_textLatex);
    _textLatex = hyperlinkReplacement(_textLatex);
    _textLatex = firstLinkReplacement(_textLatex);
    return _textLatex;
}

std::string MdFile::firstLinkReplacement(std::string text){
    std::regex hyperLink("\\\\hypertarget\\{(.*?)\\}");
    text = std::regex_replace(text, hyperLink, "\\hypertarget{" + _fileName + "}", std::regex_constants::format_first_only);

    std::regex label("\\\\label\\{(.*?)\\}");
    text = std::regex_replace(text, label, "\\label{" + _fileName + "}", std::regex_constants::format_first_only);
    return text;
}

std::string MdFile::headerReplacement(std::string text){

    for(int i=0; i < _fileNestingLevel; i++){
        text = downFileHeaders(text);
    }
    return text;
}

std::string MdFile::hyperlinkReplacement(std::string text){
    std::regex hyperLink("\\\\hypertarget\\{(.*)\\}");
    text = std::regex_replace(text, hyperLink, "\\hypertarget{" + _fileName + ":$1}");
    return text;
}

std::string MdFile::downFileHeaders(std::string text){
    std::regex paragraph("\\\\paragraph");
    text = std::regex_replace(text, paragraph, "\\subparagraph");

    std::regex subsubsection("\\\\subsubsection");
    text = std::regex_replace(text, subsubsection, "\\paragraph");

    std::regex subsection("\\\\subsection");
    text = std::regex_replace(text, subsection, "\\subsubsection");

    std::regex section("\\\\section");
    text = std::regex_replace(text, section, "\\subsection");

    return text;
}

std::string MdFile::linkReplacement(std::string text){
    std::regex label("\\\\label\\{(.*)\\}");
    text = std::regex_replace(text, label, "\\label{" + _fileName + ":$1}");
    return text;
}

void MdFile::readFile(){
    std::ifstream t(_fullFileName);
    std::stringstream buffer;
    buffer << t.rdbuf();
    _fileText = buffer.str();
}

void MdFile::setProperties(std::vector<std::string> properties){
    _properties = properties;
}

void MdFile::setFileNestingLevel(int n){
    _fileNestingLevel = n;
}

std::string MdFile::getFileName(){
    return _fileName;
}

int MdFile::getFileNestingLevel(){
    return _fileNestingLevel;
}

std::string MdFile::getFileText(){
    return _fileText;
}

std::vector<std::string> MdFile::getProperties(){
    return _properties;
}

void MdFile::setPathToFile(std::string pathToFile){
    _pathToFile = pathToFile;
}

void MdFile::setFullFileName(std::string path, std::string fileName){
    namespace fs = std::filesystem;
    fs::path dir (path);
    fs::path file (fileName);
    fs::path full_path = dir / file;
    _fullFileName = full_path.c_str();
}

std::string MdFile::getFullFileName(){
    return _fullFileName;
}
