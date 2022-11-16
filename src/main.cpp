#include <iostream>
#include "mdmfp2latex/document.hpp"

int main(int argc, char **argv){

    Document document = Document("test.tex");
    document.setDocumentStruct("/home/nikita/Документы/mdmfp2latex/tests/testdata/Struct.txt");
    document.readMdFiles();

    return 0;
}
