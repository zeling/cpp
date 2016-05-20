cmake_minimum_required(VERSION 3.3)
project(cpp)
find_package(BOOST)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES test_naive_lexer.cpp lexer.hpp macro.hpp toy.hpp naive_storage.hpp naive_lex_policy.hpp naive_lex_policy.hpp instantiate_naive_lexer.hpp toy_cpp.cxx toy_cpp.hpp)
add_executable(cpp ${SOURCE_FILES})