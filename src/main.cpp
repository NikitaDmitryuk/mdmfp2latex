#include <iostream>
#include "mdmfp2latex/document.hpp"
#include "mdmfp2latex/mdfile.hpp"

int main(int argc, char **argv){

    Document document = Document("test.tex");
    document.setSrcPath("/home/nikita/Документы/mdmfp2latex/tests/testdata");
    document.setDocumentStruct("Struct.txt");
    document.readMdFiles();
    for(MdFile mdfile : document.getMarkdownFiles()){
        std::cout << mdfile.getFileText() << std::endl;
    }
    return 0;
}
