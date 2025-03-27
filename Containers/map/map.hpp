#pragma once
#include <memory>
#include <utility>
#include <vector>
#include <algorithm>

namespace my{
    template <typename T, typename U>
    class map{
        private:
        std::vector<std::pair<T, U>> m_pairs={};
        public:
        map();

        map(std::initializer_list<std::pair<T, U>> init);

        template <typename Iterator>
        map(Iterator begin, Iterator end);

        const std::size_t size() const;

        map(const map& other);

        map(map&& other)noexcept;

        map& operator=(const map& other);

        map& operator=(map&& other)noexcept;

        U& operator[](const T& key);

        const U& operator[](const T& key) const;

        U& at(const T& key);

        const U& at(const T& key) const;

        auto begin();
        
        auto end();
        
        auto begin() const;

        auto end() const;

        auto rbegin();

        auto rend();

        auto rbegin() const;

        auto rend() const;

        bool empty()const;

        void insert(T key, U value);
    };
}

#include "map.tpp"