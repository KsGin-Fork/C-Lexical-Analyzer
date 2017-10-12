/*
 * File   : FStream
 * Author : KsGin 
 * Date   : 2017/10/12
 */

#ifndef C_LEXICAL_ANALYZER_FSTREAM_H
#define C_LEXICAL_ANALYZER_FSTREAM_H

#include <string>
#include <fstream>

class mfstream {
public:
    static void ReadFile(const std::string &file_path , std::string &text);

    static void WriteFile(const std::string &file_path , const std::string &text);
};


#endif //C_LEXICAL_ANALYZER_FSTREAM_H
