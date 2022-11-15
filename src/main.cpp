#include <iostream>
#include <string>
#include "mdmfp2latex/parser.hpp"
#include "mdmfp2latex/mdfile.hpp"

int main(int argc, char **argv){
    std::string fileName = "/home/nikita/Документы/mdmfp2latex/tests/testdata/unittest_parser.txt";
    Parser ps = Parser();
    ps.parseFrame(fileName);

    std::string mdFileName = "/home/nikita/Документы/mdmfp2latex/tests/testdata/a.md";
    MdFile mdfile = MdFile();
    mdfile.readFile(mdFileName);
    std::cout << mdfile.getMarkdownText() << std::endl;
    mdfile.convert("");
    std::cout << mdfile.getLatexText() << std::endl;
    return 0;
}
