#include "mdmfp2latex/mdfile.hpp"

MdFile::MdFile(std::string fileName){
    _fileName = fileName;
}

MdFile::~MdFile() = default;

std::string MdFile::convert(std::string flags){
    namespace bp = boost::process;
    bp::ipstream out;
    std::stringstream buffer;
    bp::child c("pandoc -f markdown -t latex /home/nikita/Документы/mdmfp2latex/tests/testdata/a.md", bp::std_out > out);
    buffer << out.rdbuf();
    std::string _textLatex = buffer.str();
    c.terminate();
    return _textLatex;
}

void MdFile::readFile(std::string srcPath){
    namespace fs = std::filesystem;
    fs::path dir (srcPath);
    fs::path file (_fileName);
    fs::path full_path = dir / file;
    std::ifstream t(full_path.c_str());
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
