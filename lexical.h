/*
 * File   : lexical
 * Author : KsGin 
 * Date   : 2017/10/12
 */

#ifndef C_LEXICAL_ANALYZER_LEXICAL_H
#define C_LEXICAL_ANALYZER_LEXICAL_H

#include <string>

class lexical {
private:
    /*定义数据类型，内部实现方法*/

    bool is_letter(char &i);

    bool is_digit(char &i);

    bool is_not_end(std::string::iterator it , const std::string &code_str , int n);

    void parse_letter(std::string::iterator &it , std::string::iterator end , std::vector<std::pair<std::string, int>> &ret);

public:
    ~lexical();
    lexical();
    /*定义公开接口*/
    int parse(std::string code_str , std::vector<std::pair<std::string , int>> &ret);

};

#endif //C_LEXICAL_ANALYZER_LEXICAL_H
