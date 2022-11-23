#include <iostream>
#include <fstream>
#include "mdmfp2latex/document.hpp"
#include "mdmfp2latex/mdfile.hpp"
#include "boost/program_options.hpp"
#include "boost/algorithm/string.hpp"
#include <string>

namespace po = boost::program_options;
int main(int argc, char** argv) {
    // Arguments will be stored here
    std::string input;
    std::string output;
    // Configure options here
    po::options_description desc ("Allowed options");
    desc.add_options ()
        ("help,h", "print usage message")
        ("input,i", po::value(&input), "Input struct file")
        ("preamble,m", po::value(&output), "Create preamble file")
        ("path,p", po::value(&output), "Path to files")
        ("output,o", po::value(&output), "Output latex file");
    // Parse command line arguments
    po::variables_map vm;
    po::store (po::command_line_parser (argc, argv).options (desc).run (), vm);
    po::notify (vm);
    // Check if there are enough args or if --help is given
    if (vm.count ("help") || !vm.count ("output") || !vm.count ("path")) {
        std::cerr << desc << "\n";
        return 1;
    }
    
    Document document = Document(vm["output"].as<std::string>());
    document.setSrcPath(vm["path"].as<std::string>());
    document.setDocumentStruct("Struct.txt");
    document.readMdFiles();
    document.convertMdFiles();
    document.createDocument();
    std::ofstream out(document.getDocumentName());
    out << document.getDocumentText();
    out.close();

    if(vm.count("preamble")){
        document.createPreamble();
    }

    return 0;
}

/*
int main(int argc, char **argv){

    Document document = Document("test.tex");
    document.setSrcPath("/home/nikita/Документы/mdmfp2latex/test");
    document.setDocumentStruct("Struct.txt");
    document.readMdFiles();
    document.convertMdFiles();
    document.createDocument();
    std::cout << document.getDocumentText() << std::endl;
    std::string outputFileName = "output.tex";
    std::ofstream out(outputFileName);
    out << document.getDocumentText();
    out.close();

    document.createPreamble();
    return 0;
}
*/
