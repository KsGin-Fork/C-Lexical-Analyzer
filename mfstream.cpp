/*
 * File   : FStream
 * Author : KsGin 
 * Date   : 2017/10/12
 */

#include "mfstream.h"

void mfstream::ReadFile(const std::string &file_path , std::string &text){
    std::ifstream in(file_path);
    std::istreambuf_iterator<char> beg(in), end;
    text.append(std::string(beg,end));
    in.close();
}

void mfstream::WriteFile(const std::string &file_path , const std::string &text){
    std::ofstream out(file_path);
    out << text;
    out.close();
}