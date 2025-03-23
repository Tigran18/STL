#pragma once
#include <memory>
#include <utility>
#include <vector>

namespace my{
    template <typename T, typename U>
    class map{
        private:
        std::vector<std::pair<T, U>> m_pairs;
        public:
        map():m_pairs({}){}

        map(std::initializer_list<std::pair<T, U>> init) {
            for (auto& el : init) {
                m_pairs.push_back(el);
            }
        }

        std::size_t size() const {
            return m_pairs.size();
        }
    };
}

#include "map.tpp"