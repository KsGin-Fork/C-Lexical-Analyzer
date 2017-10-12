#include <iostream>
#include <fstream>
#include <sstream>

std::string ReadFile(const std::string &file_path){
    std::ifstream in(file_path);
    std::istreambuf_iterator<char> beg(in), end;
    std::string str(beg, end);
    in.close();
    return str;
}


void WriteFile(const std::string &file_path , const std::string &text){
    std::ofstream out(file_path);
    out << text;
    out.close();
}

int main() {

    return 0;
}
