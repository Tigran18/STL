#include "deque.hpp"

using namespace my;

template <typename T>
std::size_t deque<T>::size()const{
    return m_vec.size();
}

template <typename T>
deque<T>::deque():m_vec({}){}

template <typename T>
deque<T>::deque(std::initializer_list<T> init):deque(){
    for(auto arg : init){
        m_vec.push_back(arg);
    }
}

template <typename T>
deque<T>::deque(const deque& other)=default;

template <typename T>
deque<T>::deque(deque&& other)noexcept{
    m_vec=std::move(other.m_vec);
}

template <typename T>
deque<T>& deque<T>::operator=(const deque& other){
    if(this!=&other){
        m_vec=other.m_vec;
    }
    return *this;
}

template <typename T>
deque<T>& deque<T>::operator=(deque&& other)noexcept{
    if(this!=&other){
        m_vec=std::move(other.m_vec);
    }
    return *this;
}

template <typename T>
void deque<T>::push_back(T arg){
    m_vec.push_back(arg);
}

template <typename T>
void deque<T>::push_front(T arg) {
    m_vec.insert(m_vec.begin(), arg);
}

template <typename T>
void deque<T>::pop_back(){
    m_vec.pop_back();
}

template <typename T>
void deque<T>::pop_front(){
    m_vec.erase(m_vec.begin());
}

template <typename T>
T deque<T>::front()const{
    if(m_vec.size()<=0){
        throw std::out_of_range("No element to print.");
    }
    return m_vec.front();
}

template <typename T>
T deque<T>::back()const{
    if(m_vec.size()<=0){
        throw std::out_of_range("No element to print.");
    }
    return m_vec.back();
}

template <typename T>
T& deque<T>::at(const std::size_t& k){
    if(k>=m_vec.size()){
        throw std::out_of_range("Out of bounds.");
    }
    return m_vec.at(k);
}

template <typename T>
const T& deque<T>::at(const std::size_t& k)const{
    if(k>=m_vec.size()){
        throw std::out_of_range("Out of bounds.");
    }
    return m_vec.at(k);
}

template <typename T>
const T& deque<T>::operator[](const std::size_t k)const{
    return m_vec[k];
}

template <typename T>
T& deque<T>::operator[](const std::size_t k){
    return m_vec[k];
}