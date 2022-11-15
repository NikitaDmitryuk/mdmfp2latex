#include "mdmfp2latex/file.hpp"

File::~File() = default;

std::string File::getMarkdownText(){
    return _textMarkdown;
}

std::string File::getLatexText(){
    return _textLatex;
}
