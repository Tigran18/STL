#pragma once
#include <memory>
#include <utility>
#include <vector>

namespace my{
    template <typename T, typename U>
    class map{
        private:
        std::vector<std::pair<T, U>> m_pairs={};
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

        map(const map& other)=default;

        map(map&& other)noexcept{
            m_pairs=std::move(other.m_pairs);
        }

        map& operator=(const map& other){
            if(this!=&other){
                m_pairs.clear();
                for(auto& pair : other.m_pairs){
                    m_pairs.push_back(pair);
                }
            }
            return *this;
        }

        map& operator=(map&& other)noexcept{
            if(this!=&other){
                m_pairs=std::move(other.m_pairs);
            }
            return *this;
        }

        U& operator[](const T& key){
            for(auto& pair : m_pairs){
                if(pair.first==key){
                    return pair.second;
                }
            }
            m_pairs.push_back({key, U{}});
            return m_pairs.back().second;
        }
    };
}

#include "map.tpp"