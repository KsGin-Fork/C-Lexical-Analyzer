cmake_minimum_required(VERSION 3.8)
project(C_Lexical_Analyzer)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp lexical.h lexical.cpp test.h mfstream.cpp mfstream.h)
add_executable(C_Lexical_Analyzer ${SOURCE_FILES})