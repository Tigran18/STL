#include "deque.hpp"

using namespace my;

template <typename T>
std::size_t deque<T>::size()const{
    return m_size;
}

template <typename T>
deque<T>::deque():m_vec({}), m_size(0){}

template <typename T>
deque<T>::deque(std::initializer_list<T> init):deque(){
    for(auto arg : init){
        m_vec.push_back(arg);
        ++m_size;
    }
}

template <typename T>
deque<T>::deque(const deque& other)=default;

template <typename T>
deque<T>::deque(deque&& other)noexcept{
    m_vec=std::move(other.m_vec);
    m_size=other.m_size;
    other.m_size=0;
}

template <typename T>
deque<T>& deque<T>::operator=(const deque& other){
    if(this!=&other){
        m_vec=other.m_vec;
        m_size=other.m_size;
    }
    return *this;
}

template <typename T>
deque<T>& deque<T>::operator=(deque&& other)noexcept{
    if(this!=&other){
        m_vec=std::move(other.m_vec);
        m_size=other.m_size;
    }
}

template <typename T>
T deque<T>::front()const{
    if(m_size<=0){
        throw std::out_of_range("No element to print.");
    }
    return m_vec.front();
}

template <typename T>
T deque<T>::back()const{
    if(m_size<=0){
        throw std::out_of_range("No element to print.");
    }
    return m_vec.back();
}