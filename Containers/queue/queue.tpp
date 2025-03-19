#include "queue.hpp"

using namespace my;

template <typename T>
queue<T>::queue():m_queue({}), m_size(0){}

template <typename T>
queue<T>::queue(std::initializer_list<T> init):queue(){
    for(auto& arg: init){
        m_queue.push_back(arg);
        ++m_size;
    }
}

template <typename T>
queue<T>::queue(const queue& other)=default;

template <typename T>
queue<T>::queue(queue&& other)noexcept: m_queue(std::move(other.m_queue)), m_size(other.m_size){
    other.m_size=0:
}

template <typename T>
std::size_t queue<T>::size(){
    return m_size;
}

template <typename T>
bool queue<T>::empty(){
    return m_size>0?1:0;
}

template <typename T>
void queue<T>::push(const T& value){
    m_queue.push_back(value);
    ++m_size;
}

template <typename T>
void queue<T>::pop(){
    if(m_size==0) throw std::out_of_range("No element to delete");
    m_queue.pop_back();
    --m_size;
}

template <typename T>
void queue<T>::clear(){
    while(m_size!=0){
        pop();
    }
}

template <typename T>
T& queue<T>::front()const{
    return m_queue.front();
}

template <typename T>
T& queue<T>::back()const{
    return m_queue.back();
}