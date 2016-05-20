//
// Created by Zeling on 16/5/17.
//

#ifndef CPP_CPP_LEXER_HPP
#define CPP_CPP_LEXER_HPP

#include <iostream>
#include <boost/spirit/home/classic/iterator/multi_pass.hpp>

template <typename LexPolicy, typename StoragePolicy>
class lexer : public LexPolicy, public StoragePolicy {
public:
    
    typedef typename LexPolicy::token_type token_type;
    typedef typename LexPolicy::iterator_type iterator_type;
    typedef typename LexPolicy::char_type char_type;
    typedef LexPolicy lex_policy_type;
    typedef StoragePolicy storage_policy_type;

    explicit lexer(std::istream& is)
            :it_(iterator_type(is)), lex_policy_type(), storage_policy_type()
    { }

    explicit lexer(iterator_type& it)
            :it_(it), lex_policy_type(), storage_policy_type()
    { }


    bool operator() () {
        iterator_type begin = it_;
        typename token_type::token_t ty = this->lex(it_);
        this->store(begin, it_, ty);
    }


private:
    iterator_type it_;
    iterator_type end_;
};

#endif //CPP_CPP_LEXER_HPP
