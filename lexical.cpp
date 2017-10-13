/*
 * File   : lexical
 * Author : KsGin 
 * Date   : 2017/10/12
 */

#include <vector>
#include "lexical.h"
#include <sstream>

lexical::~lexical() {

}

lexical::lexical() {

}

int lexical::parse(std::string code_str, std::vector<std::pair<std::string, int>> ret) {

    for (auto it = code_str.begin(); it != code_str.end(); ++it) {
        switch (*it) {
            //忽略非字符单位
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                break;

                //忽略注释
            case '/': {
                if (*(it + 1) == '/') {
                    it += 2;
                    while (it != code_str.end() && *it != '\n') it++;
                } else if (*(it + 1) == '*') {
                    it += 2;
                    while (it != code_str.end() && it + 1 != code_str.end()) {
                        if (*it == '*' && *(it + 1) == '/') {
                            it++;
                            break;
                        }
                        it++;
                    }
                } else {
                    ret.emplace_back("/", 23);
                }
                break;
            }
                //解析数字
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9': {
                std::stringstream digit_str;
                while (*it >= '0' && *it <= '9') {
                    digit_str << *it;
                    it++;
                }
                //p1.
                ret.emplace_back(digit_str.str(), 25);
                break;
            }
                //解析标识符或者变量
            case 'a':
            case 'b':
            {
                if (*(it + 1) == 'r' && *(it + 2) == 'e' && *(it + 3) == 'a' && *(it + 4) == 'k'
                    && !is_letter(*(it + 5)) && !is_digit(*(it + 5))) {
                    it += 5;
                    ret.emplace_back("break", 45);
                    break;
                }
            }
            case 'c': {
                if (*(it + 1) == 'h' && *(it + 2) == 'a' && *(it + 3) == 'r'
                    && !is_letter(*(it + 4)) && !is_digit(*(it + 4))) {
                    it += 4;
                    ret.emplace_back("char", 30);
                    break;
                }
                if (*(it + 1) == 'a' && *(it + 2) == 's' && *(it + 3) == 'e'
                    && !is_letter(*(it + 4)) && !is_digit(*(it + 4))) {
                    it += 4;
                    ret.emplace_back("case", 41);
                    break;
                }
                if (*(it + 1) == 'o' && *(it + 2) == 'n' && *(it + 3) == 's' && *(it + 4) == 't'
                    && !is_letter(*(it + 5)) && !is_digit(*(it + 5))) {
                    it += 5;
                    ret.emplace_back("const", 50);
                    break;
                }
                if (*(it + 1) == 'o' && *(it + 2) == 'n' && *(it + 3) == 't'
                    && *(it + 4) == 'i' && *(it + 5) == 'n' && *(it + 6) == 'u' && *(it + 7) == 'e'
                    && !is_letter(*(it + 8)) && !is_digit(*(it + 8))) {
                    it += 8;
                    ret.emplace_back("continue", 41);
                    break;
                }

            }
            case 'd':
            {
                if (*(it + 1) == 'o' && !is_letter(*(it + 2)) && !is_digit(*(it + 2))) {
                    it += 2;
                    ret.emplace_back("do", 36);
                    break;
                }

                if (*(it + 1) == 'o' && *(it + 2) == 'u' && *(it + 3) == 'b'
                    && *(it + 4) == 'l' && *(it+5) == 'e'
                    && !is_letter(*(it + 6)) && !is_digit(*(it + 6))) {
                    it += 6;
                    ret.emplace_back("double", 29);
                    break;
                }
            }
            case 'e':
            case 'f':
            case 'g':
            case 'h':
            case 'i':
            case 'j':
            case 'k':
            case 'l':
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r':
            case 's':
            case 't':
            case 'u':
            case 'v':
            case 'w':
            case 'x':
            case 'y':
            case 'z':
            case 'A':
            case 'B':
            case 'C':
            case 'D':
            case 'E':
            case 'F':
            case 'G':
            case 'H':
            case 'I':
            case 'J':
            case 'K':
            case 'L':
            case 'M':
            case 'N':
            case 'O':
            case 'P':
            case 'Q':
            case 'R':
            case 'S':
            case 'T':
            case 'U':
            case 'V':
            case 'W':
            case 'X':
            case 'Y':
            case 'Z':
            case '_': {
                std::stringstream word_str;
                while (is_letter(*it) || is_digit(*it)) {
                    word_str << *it;
                    it++;
                }
                ret.emplace_back(word_str.str() , 26);
                break;
            }
        }
    }

    return 0;
}

bool lexical::is_letter(char &i) {
    return i >= 'a' && i <= 'z' || i >= 'A' && i <= 'Z' || i == '_';
}

bool lexical::is_digit(char &i) {
    return i >= '0' && i <= '9';
}

