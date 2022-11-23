#include <iostream>
#include <fstream>
#include "mdmfp2latex/document.hpp"
#include "mdmfp2latex/mdfile.hpp"

int main(int argc, char **argv){

    Document document = Document("test.tex");
    document.setSrcPath("/home/nikita/Документы/mdmfp2latex/test");
    document.setDocumentStruct("Struct.txt");
    document.readMdFiles();
    document.convertMdFiles();
    document.createDocument();
    // for(MdFile mdfile : document.getMarkdownFiles()){
    //     std::cout << mdfile.getFileText() << std::endl;
    // }
    // for(auto text : document.getLatexText()){
    //     std::cout << text << std::endl;
    // }
    std::cout << document.getDocumentText() << std::endl;
    std::string outputFileName = "output.tex";
    std::ofstream out(outputFileName);
    out << document.getDocumentText();
    out.close();

    document.createPreamble();
    return 0;
}
