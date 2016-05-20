//
// Created by Zeling on 16/5/20.
//

#ifndef CPP_INSTANTIATE_NAIVE_LEXER_HPP
#define CPP_INSTANTIATE_NAIVE_LEXER_HPP

#include "lexer.hpp"
#include "naive_lex_policy.hpp"
#include "naive_storage.hpp"

typedef lexer<naive_lex_policy, naive_storage<naive_token>> naive_lexer;

#endif //CPP_INSTANTIATE_NAIVE_LEXER_HPP
