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


bool lexical::is_letter(char &i) {
    return (i >= 'a' && i <= 'z') || (i >= 'A' && i <= 'Z') || i == '_';
}

bool lexical::is_digit(char &i) {
    return i >= '0' && i <= '9';
}

bool lexical::is_not_end(std::string::iterator it, const std::string &code_str, int n) {
    for (int i = 1; i < n; ++i) {
        if ((it + i) == code_str.end()) return false;
    }
    return true;
}

void lexical::parse_letter(std::string::iterator &it, std::string::iterator end,
                           std::vector<std::pair<std::string, int>> &ret) {
    std::stringstream word_str;
    while (it != end && is_letter(*it) || is_digit(*it)) {
        word_str << *it;
        it++;
    }
    it--; //回溯一个字符
    ret.emplace_back(word_str.str(), 26);
}

int lexical::parse(std::string code_str, std::vector<std::pair<std::string, int>> &ret) {
    for (auto it = code_str.begin(); it != code_str.end() && *it != '\0'; ++it) {
        switch (*it) {
            //忽略非字符单位
            case ' ':
            case '\t':
            case '\r':
            case '\n':
                break;

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
            case 'b': {
                if (is_not_end(it, code_str, 5) && *(it + 1) == 'r' && *(it + 2) == 'e' && *(it + 3) == 'a' &&
                    *(it + 4) == 'k'
                    && !is_letter(*(it + 5)) && !is_digit(*(it + 5))) {
                    it += 5;
                    ret.emplace_back("break", 45);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 'c': {
                if (is_not_end(it, code_str, 4) &&
                    *(it + 1) == 'h' && *(it + 2) == 'a' && *(it + 3) == 'r'
                    && !is_letter(*(it + 4)) && !is_digit(*(it + 4))) {
                    it += 4;
                    ret.emplace_back("char", 30);
                    break;
                }
                if (is_not_end(it, code_str, 4) &&
                    *(it + 1) == 'a' && *(it + 2) == 's' && *(it + 3) == 'e'
                    && !is_letter(*(it + 4)) && !is_digit(*(it + 4))) {
                    it += 4;
                    ret.emplace_back("case", 41);
                    break;
                }
                if (is_not_end(it, code_str, 5) &&
                    *(it + 1) == 'o' && *(it + 2) == 'n' && *(it + 3) == 's' && *(it + 4) == 't'
                    && !is_letter(*(it + 5)) && !is_digit(*(it + 5))) {
                    it += 5;
                    ret.emplace_back("const", 50);
                    break;
                }
                if (is_not_end(it, code_str, 8) &&
                    *(it + 1) == 'o' && *(it + 2) == 'n' && *(it + 3) == 't'
                    && *(it + 4) == 'i' && *(it + 5) == 'n' && *(it + 6) == 'u' && *(it + 7) == 'e'
                    && !is_letter(*(it + 8)) && !is_digit(*(it + 8))) {
                    it += 8;
                    ret.emplace_back("continue", 41);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 'd': {
                if (is_not_end(it, code_str, 2) &&
                    *(it + 1) == 'o' && !is_letter(*(it + 2)) && !is_digit(*(it + 2))) {
                    it += 2;
                    ret.emplace_back("do", 36);
                    break;
                }

                if (is_not_end(it, code_str, 6) &&
                    *(it + 1) == 'o' && *(it + 2) == 'u' && *(it + 3) == 'b'
                    && *(it + 4) == 'l' && *(it + 5) == 'e'
                    && !is_letter(*(it + 6)) && !is_digit(*(it + 6))) {
                    it += 6;
                    ret.emplace_back("double", 29);
                    break;
                }

                if (is_not_end(it, code_str, 7) &&
                    *(it + 1) == 'e' && *(it + 2) == 'f' && *(it + 3) == 'a'
                    && *(it + 4) == 'i' && *(it + 5) == 'l' && *(it + 6) == 't'
                    && !is_letter(*(it + 7)) && !is_digit(*(it + 7))) {
                    it += 7;
                    ret.emplace_back("default", 51);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 'e': {
                if (is_not_end(it, code_str, 4) &&
                    *(it + 1) == 'n' && *(it + 2) == 'u' && *(it + 3) == 'm'
                    && !is_letter(*(it + 4)) && !is_digit(*(it + 4))) {
                    it += 4;
                    ret.emplace_back("enum", 47);
                    break;
                }
                if (is_not_end(it, code_str, 4) &&
                    *(it + 1) == 'l' && *(it + 2) == 's' && *(it + 3) == 'e'
                    && !is_letter(*(it + 4)) && !is_digit(*(it + 4))) {
                    it += 4;
                    ret.emplace_back("else", 41);
                    break;
                }
                if (is_not_end(it, code_str, 6) && *(it + 1) == 'x' && *(it + 2) == 't' && *(it + 3) == 'e'
                    && *(it + 4) == 'r' && *(it + 5) == 'n'
                    && !is_letter(*(it + 6)) && !is_digit(*(it + 6))) {
                    it += 6;
                    ret.emplace_back("extern", 52);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 'f': {
                if (is_not_end(it, code_str, 3) && *(it + 1) == 'o' && *(it + 2) == 'r'
                    && !is_letter(*(it + 3)) && !is_digit(*(it + 3))) {
                    it += 3;
                    ret.emplace_back("for", 46);
                    break;
                }
                if (is_not_end(it, code_str, 5) && *(it + 1) == 'l' && *(it + 2) == 'o' && *(it + 3) == 'a'
                    && *(it + 4) == 't'
                    && !is_letter(*(it + 5)) && !is_digit(*(it + 5))) {
                    it += 5;
                    ret.emplace_back("float", 28);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 'g':
            case 'h':
            case 'i': {
                if (is_not_end(it, code_str, 2) && *(it + 1) == 'f'
                    && !is_letter(*(it + 2)) && !is_digit(*(it + 2))) {
                    it += 2;
                    ret.emplace_back("if", 38);
                    break;
                }
                if (is_not_end(it, code_str, 3) && *(it + 1) == 'n' && *(it + 2) == 't'
                    && !is_letter(*(it + 3)) && !is_digit(*(it + 3))) {
                    it += 3;
                    ret.emplace_back("int", 27);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 'j':
            case 'k':
            case 'l': {
                if (is_not_end(it, code_str, 3) && *(it + 1) == 'o' && *(it + 2) == 'n' && *(it + 3) == 'g'
                    && !is_letter(*(it + 4)) && !is_digit(*(it + 4))) {
                    it += 4;
                    ret.emplace_back("long", 31);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 'm':
            case 'n':
            case 'o':
            case 'p':
            case 'q':
            case 'r': {
                if (is_not_end(it, code_str, 6) && *(it + 1) == 'e' && *(it + 2) == 't' && *(it + 3) == 'u'
                    && *(it + 4) == 'r' && *(it + 5) == 'n'
                    && !is_letter(*(it + 6)) && !is_digit(*(it + 6))) {
                    it += 6;
                    ret.emplace_back("return", 42);
                    break;
                }
                if (is_not_end(it, code_str, 8) && *(it + 1) == 'e' && *(it + 2) == 'g' && *(it + 3) == 'i'
                    && *(it + 4) == 's' && *(it + 5) == 't' && *(it + 6) == 'e' && *(it + 7) == 'r'
                    && !is_letter(*(it + 8)) && !is_digit(*(it + 8))) {
                    it += 8;
                    ret.emplace_back("register", 44);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 's': {
                if (is_not_end(it, code_str, 5) && *(it + 1) == 'h' && *(it + 2) == 'o' && *(it + 3) == 'r'
                    && *(it + 4) == 't'
                    && !is_letter(*(it + 5)) && !is_digit(*(it + 5))) {
                    it += 5;
                    ret.emplace_back("short", 32);
                    break;
                }
                if (is_not_end(it, code_str, 6) && *(it + 1) == 't' && *(it + 2) == 'r' && *(it + 3) == 'u'
                    && *(it + 4) == 'c' && *(it + 5) == 't'
                    && !is_letter(*(it + 6)) && !is_digit(*(it + 6))) {
                    it += 6;
                    ret.emplace_back("struct", 33);
                    break;
                }
                if (is_not_end(it, code_str, 6) && *(it + 1) == 'w' && *(it + 2) == 'i' && *(it + 3) == 't'
                    && *(it + 4) == 'c' && *(it + 5) == 'h'
                    && !is_letter(*(it + 6)) && !is_digit(*(it + 6))) {
                    it += 6;
                    ret.emplace_back("switch", 40);
                    break;
                }
                if (is_not_end(it, code_str, 6) && *(it + 1) == 'i' && *(it + 2) == 'g' && *(it + 3) == 'n'
                    && *(it + 4) == 'e' && *(it + 5) == 'd'
                    && !is_letter(*(it + 6)) && !is_digit(*(it + 6))) {
                    it += 6;
                    ret.emplace_back("signed", 49);
                    break;
                }
                if (is_not_end(it, code_str, 6) && *(it + 1) == 't' && *(it + 2) == 'a' && *(it + 3) == 't'
                    && *(it + 4) == 'i' && *(it + 5) == 'c'
                    && !is_letter(*(it + 6)) && !is_digit(*(it + 6))) {
                    it += 6;
                    ret.emplace_back("static", 53);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 't':
            {
                if (is_not_end(it, code_str, 7) && *(it + 1) == 'y' && *(it + 2) == 'p' && *(it + 3) == 'e'
                    && *(it + 4) == 'd' && *(it + 5) == 'e' && *(it+6) == 'f'
                    && !is_letter(*(it + 7)) && !is_digit(*(it + 7))) {
                    it += 7;
                    ret.emplace_back("typedef", 48);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 'u':
            {
                if (is_not_end(it, code_str, 5) && *(it + 1) == 'n' && *(it + 2) == 'i' && *(it + 3) == 'o'
                    && *(it + 4) == 'n'
                    && !is_letter(*(it + 5)) && !is_digit(*(it + 5))) {
                    it += 5;
                    ret.emplace_back("union", 34);
                    break;
                }
                if (is_not_end(it, code_str, 8) && *(it + 1) == 'n' && *(it + 2) == 's' && *(it + 3) == 'i'
                    && *(it + 4) == 'g' && *(it + 5) == 'n' && *(it+6) == 'e' && *(it+7) == 'd'
                    && !is_letter(*(it + 8)) && !is_digit(*(it + 8))) {
                    it += 8;
                    ret.emplace_back("unsigned", 35);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 'v':{
                if (is_not_end(it, code_str, 8) && *(it + 1) == 'o' && *(it + 2) == 'l' && *(it + 3) == 'a'
                    && *(it + 4) == 't' && *(it + 5) == 'i' && *(it+6) == 'l' && *(it+7) == 'e'
                    && !is_letter(*(it + 8)) && !is_digit(*(it + 8))) {
                    it += 8;
                    ret.emplace_back("volatile", 54);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case 'w':{
                if (is_not_end(it, code_str, 5) && *(it + 1) == 'h' && *(it + 2) == 'i' && *(it + 3) == 'l'
                    && *(it + 4) == 'e'
                    && !is_letter(*(it + 5)) && !is_digit(*(it + 5))) {
                    it += 5;
                    ret.emplace_back("while", 37);
                    break;
                }
                parse_letter(it, code_str.end(), ret);
                break;
            }
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
                parse_letter(it, code_str.end(), ret);
                break;
            }
            case '.': {
                ret.emplace_back("." , 0);
                break;
            }
            case '+': {
                ret.emplace_back("+" , 1);
                break;
            }
            case '-': {
                ret.emplace_back("-" , 2);
                break;
            }
            case '*': {
                ret.emplace_back("*" , 3);
                break;
            }
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
                    ret.emplace_back("/", 4);
                }
                break;
            }
            case '(': {
                ret.emplace_back("(" , 5);
                break;
            }
            case ')': {
                ret.emplace_back(")" , 6);
                break;
            }
            case '[': {
                ret.emplace_back("[" , 7);
                break;
            }
            case ']': {
                ret.emplace_back("]" , 8);
                break;
            }
            case '{': {
                ret.emplace_back("{" , 9);
                break;
            }
            case '}': {
                ret.emplace_back("}" , 10);
                break;
            }
            case '&': {
                if((it+1) != code_str.end() && *(it+1) == '&'){
                    ret.emplace_back("&&" , 12);
                    it++;
                    break;
                }
                ret.emplace_back("&" , 11);
                break;
            }
            case '<': {
                ret.emplace_back("<" , 13);
                break;
            }
            case '>': {
                ret.emplace_back(">" , 14);
                break;
            }
            case '=': {
                ret.emplace_back("=" , 15);
                break;
            }
            case ':': {
                ret.emplace_back(":" , 16);
                break;
            }
            case '#': {
                ret.emplace_back("#" , 17);
                break;
            }
            case '?': {
                ret.emplace_back("?" , 18);
                break;
            }
            case '%': {
                ret.emplace_back("%" , 19);
                break;
            }
            case '!': {
                ret.emplace_back("!" , 20);
                break;
            }
            case '\'': {
                ret.emplace_back("\'" , 21);
                break;
            }
            case '\"': {
                ret.emplace_back("\"" , 22);
                break;
            }
            case '|': {
                if((it+1) != code_str.end() && *(it+1) == '|'){
                    ret.emplace_back("||" , 24);
                    it++;
                    break;
                }
                ret.emplace_back("|" , 23);
                break;
            }

            default:
                break;
        }
    }

    return 0;
}

