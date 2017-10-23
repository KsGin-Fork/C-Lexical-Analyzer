#include <iostream>
#include "mfstream.h"
#include "lexical.h"
#include <vector>
#include <sstream>

int main(int argc , char* argv[]) {

    lexical lex;
    std::string code_str;
    mfstream::ReadFile(argv[1] , code_str);

    std::vector<std::pair<std::string , int>> vp(0);

    lex.parse(code_str , vp);

    std::stringstream ss;

    for (const auto &p : vp) {
        ss << '<' << p.first << ',' << p.second << '>' << std::endl;
    }

    std::cout << ss.str();

    mfstream::WriteFile(argv[2] , ss.str());

    return 0;
}
