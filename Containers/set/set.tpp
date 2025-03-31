#include "set.hpp"

using namespace my;

template <typename T>
set<T>::set()=default;

template <typename T>
set<T>::set(std::initializer_list<T> init){
    for(auto& el : init){
        if(check(*this, el)){
            m_set.push_back(el);
        }
    }
    std::sort(m_set.begin(), m_set.end());
}

template <typename T>
set<T>::set(const set& other)=default;

template <typename T>
set<T>::set(set&& other)noexcept{
    m_set=std::move(other.m_set);
}

template <typename T>
set<T>& set<T>::operator=(const set& other){
    if(this!=&other){
        m_set=other.m_set;
    }
    return *this;
}

template <typename T>
set<T>& set<T>::operator=(set&& other)noexcept{
    if(this!=&other){
        m_set=std::move(other.m_set);
    }
    return *this;
}

template <typename T>
auto set<T>::begin(){
    return m_set.begin();
}

template <typename T>
auto set<T>::begin()const{
    return m_set.begin();
}

template <typename T>
auto set<T>::end(){
    return m_set.end();
}

template <typename T>
auto set<T>::end()const{
    return m_set.end();
}
