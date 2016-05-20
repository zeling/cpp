//
// Created by Zeling on 16/5/20.
//

#ifndef CPP_NAIVE_LEX_POLICY_HPP
#define CPP_NAIVE_LEX_POLICY_HPP

#include <iosfwd>
#include <boost/spirit/home/classic/iterator/multi_pass.hpp>

struct naive_token {
public:
    enum token_t {
        T_IDENT,
        T_WS,
        T_PUNC
    };

    enum token_t token_ty;
    std::string value;

    template<typename iterator>
    naive_token(iterator begin, iterator end, token_t t)
            : value(begin, end), token_ty(t)
    {}

};

/* unfinished */
class naive_lex_policy {
public:

    enum class lex_state {
        L_COMMENT,
        L_ESCAPENEWLINE,
        L_NORMAL,
        L_PUNC,
    };

    typedef char char_type;
    typedef naive_token token_type;
    typedef typename boost::spirit::classic::multi_pass<std::istreambuf_iterator<char_type>> iterator_type;
    typedef typename naive_token::token_t token_t;

    token_t lex(iterator_type &it) {
        using lex_state::L_COMMENT;
        using lex_state::L_ESCAPENEWLINE;
        using lex_state::L_NORMAL;
        using lex_state::L_PUNC;

        while (it != end_) {
            switch (state_) {
            case L_NORMAL:

                if (*it>='A' && *it<='Z' || *it>='a' && *it<='z' || *it>='0' && *it<='9') {
                    ++it;
                    continue;
                } else {
                    if (*it==' ' || *it=='\n' || *it=='\r' || *it=='\t') {

                    }
                    if (*it=='/') {
                        ++it;
                        if (*it=='*') {
                            state_ = L_COMMENT;
                            continue;
                        }
                        else if (*it=='/') {
                            while (*it!='\n' && state_!=L_ESCAPENEWLINE) {
                                ++it;
                            }
                            ++it;
                            return token_t::T_WS;
                        }
                    }
                    return token_t::T_IDENT;
                    break;
                    case L_COMMENT:
                        comment:
                        while (*it!='*') ++it;
                    ++it;
                    if (*it == '/') {
                        ++it;
                        state_ = L_NORMAL;
                        return token_t::T_WS;
                    }
                    break;
                    case L_ESCAPENEWLINE:
                        break;
                    default:
                        return token_t::T_WS;
                }
            }
        }
    }

private:
    iterator_type end_;
    enum lex_state state_{lex_state::L_NORMAL};
};

#endif //CPP_NAIVE_LEX_POLICY_HPP
