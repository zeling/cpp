#include <iostream>
#include <fstream>
#include <sstream>
#include <boost/spirit/home/classic/iterator/multi_pass.hpp>
#include <vector>
#include "instantiate_naive_lexer.hpp"
#include "toy.hpp"


int main_()
{

//    boost::spirit::classic::multi_pass<std::istreambuf_iterator<char>> it(std::cin);

    std::istringstream iss("//abcdefg\n/*abc*/");

//    toy_lexer t_lexer(std::cin);
//
//    t_lexer();
//    t_lexer();
//    t_lexer();

//    for (auto it = t_lexer.begin(); it!=t_lexer.end(); ++it) {
//        std::cout << it->s_ << '\n';
//    }


    naive_lexer n_lexer(iss);


    n_lexer();
    n_lexer();
    auto it = n_lexer.begin();
    std::cout << it->value << it->token_ty << '\n';
    ++it;
    std::cout << it->value << it->token_ty << '\n';
//
//
//

//    std::stringstream ss("abcd lsjdc asd");
//    naive_lexer n_lexer(ss);
//
//    std::string ret;
//    naive_lexer::token_type t;
//
//    t = n_lexer(ret);
//    if (t == naive_lexer::T_IDENT) {
//        std::cout << ret;
//    }
//
    return 0;
}