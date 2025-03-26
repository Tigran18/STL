#include "map.hpp"

using namespace my;

template <typename T, typename U>
map<T, U>::map():m_pairs({}){}

template <typename T, typename U>
map<T, U>::map(std::initializer_list<std::pair<T, U>> init) {
    for (auto& el : init) {
        m_pairs.push_back(el);
    }
}

template <typename T, typename U>
const std::size_t map<T, U>::size() const {
    return m_pairs.size();
}

template <typename T, typename U>
map<T, U>::map(const map& other)=default;

template <typename T, typename U>
map<T, U>::map(map&& other)noexcept{
    m_pairs=std::move(other.m_pairs);
}

template <typename T, typename U>
map<T, U>& map<T, U>::operator=(const map& other){
    if(this!=&other){
        m_pairs.clear();
        for(auto& pair : other.m_pairs){
            m_pairs.push_back(pair);
        }
    }
    return *this;
}

template <typename T, typename U>
map<T, U>& map<T, U>::operator=(map&& other)noexcept{
    if(this!=&other){
        m_pairs=std::move(other.m_pairs);
    }
    return *this;
}

template <typename T, typename U>
U& map<T, U>::operator[](const T& key){
    for(auto& pair : m_pairs){
        if(pair.first==key){
            return pair.second;
        }
    }
    m_pairs.push_back({key, U{}});
    return m_pairs.back().second;
}

template <typename T, typename U>
const U& map<T, U>::operator[](const T& key)const {
    for(auto& pair : m_pairs){
        if(pair.first==key){
            return pair.second;
        }
    }
    m_pairs.push_back({key, U{}});
    return m_pairs.back().second;
}

template <typename T, typename U>
auto map<T, U>::begin() { 
    return m_pairs.begin(); 
}

template <typename T, typename U>
auto map<T, U>::end() { 
    return m_pairs.end(); 
}

template <typename T, typename U>
auto map<T, U>::begin() const { 
    return m_pairs.begin(); 
}

template <typename T, typename U>
auto map<T, U>::end() const { 
    return m_pairs.end(); 
}

template <typename T, typename U>
U& map<T, U>::at(const T& key){
    for(auto& pair : m_pairs){
        if(key==pair.first){
            return pair.second;
        }
    }
    throw std::out_of_range("Out of range");
}

template <typename T, typename U>
const U& map<T, U>::at(const T& key) const{
    for(auto& pair : m_pairs){
        if(key==pair.first){
            return pair.second;
        }
    }
    throw std::out_of_range("Out of range");
}