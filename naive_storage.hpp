//
// Created by Zeling on 16/5/20.
//

#ifndef CPP_NAIVE_STORAGE_HPP
#define CPP_NAIVE_STORAGE_HPP

#include <vector>

template<typename TokenT>
class naive_storage {
public:

    typedef typename std::vector<TokenT>::iterator storage_iterator;

    template<typename ...Args>
    void store(Args&& ...args)
    {

        this->vector_.emplace_back(std::forward<Args>(args)...);
    }

    template<typename Iterator>
    naive_storage(Iterator begin, Iterator end)
            : vector_(begin, end)
    {}

    naive_storage() {}

    storage_iterator begin()
    {
        return this->vector_.begin();
    }

    storage_iterator end()
    {
        return this->vector_.end();
    }

private:
    std::vector<TokenT> vector_;
};

#endif //CPP_NAIVE_STORAGE_HPP
