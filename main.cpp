#include <iostream>
#include "mfstream.h"
#include "lexical.h"
#include <vector>

int main() {

    lexical lex;
    std::string code_str;
    mfstream::ReadFile("../input.txt" , code_str);

    std::vector<std::pair<std::string , int>> vp(0);

    lex.parse(code_str , vp);

    for (const auto &p : vp) {
        std::cout << '<' << p.first << ',' << p.second << '>' << std::endl;
    }
    return 0;
}
