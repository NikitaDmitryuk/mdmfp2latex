#include "mdmfp2latex/mdfile.hpp"
#include "boost/process.hpp"

MdFile::MdFile(){}

MdFile::~MdFile() = default;

void MdFile::convert(std::string flags){
    namespace bp = boost::process;
    bp::ipstream out;
    std::stringstream buffer;
    bp::child c("pandoc -f markdown -t latex /home/nikita/Документы/mdmfp2latex/tests/testdata/a.md", bp::std_out > out);
    buffer << out.rdbuf();
    _textLatex = buffer.str();
    c.terminate();
}

void MdFile::readFile(std::string fileName){
    std::ifstream t(fileName);
    std::stringstream buffer;
    buffer << t.rdbuf();
    _textMarkdown = buffer.str();
}
