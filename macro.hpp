//
// Created by Zeling on 16/5/17.
//

#ifndef CPP_MACRO_EXPANDER_HPP
#define CPP_MACRO_EXPANDER_HPP

template <typename Iterator, typename ExpandPolicy>
class macro : public ExpandPolicy {
public:
    typedef Iterator iterator;

    iterator expand() {

    }


};

#endif //CPP_MACRO_EXPANDER_HPP
