//
// Created by Zeling on 16/5/20.
//

/* Still found there is too much work load on the last day to write an even naive lexer */

#ifndef CPP_TOY_HPP
#define CPP_TOY_HPP

#include <iosfwd>
#include <vector>

#include "lexer.hpp"
#include "naive_storage.hpp"

//struct line {
//
//    typedef bool token_t;
//
//    std::string s_;
//
//    line (const std::string &s)
//            :s_(s)
//    {}
//};
//
//std::istream& operator>>(std::istream& is,line& data)
//{
//    std::getline(is, data.s_);
//    return is;
//}
//
//
//class toy_lex_policy {
//public:
//    typedef line token_type;
//    typedef std::string char_type;
//    typedef typename std::istreambuf_iterator<token_type> iterator_type;
//
//    bool lex(iterator_type it) {
//        if (it != this->end_) {
//            ++it;
//            return true;
//        }
//        return false;
//    }
//
//private:
//    iterator_type end_;
//};
//
//typedef lexer<toy_lex_policy, naive_storage<std::string>> toy_lexer;
//
//
//
#endif //CPP_TOY_HPP
