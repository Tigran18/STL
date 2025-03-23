#include "queue.hpp"

using namespace my;

template <typename T>
queue<T>::queue():m_queue({}){}

template <typename T>
queue<T>::queue(std::initializer_list<T> init):queue(){
    for(auto& arg: init){
        m_queue.push_back(arg);
    }
}

template <typename T>
queue<T>::queue(const queue& other)=default;

template <typename T>
queue<T>::queue(queue&& other)noexcept{
    m_queue=std::move(other.m_queue);
}

template <typename T>
queue<T>& queue<T>::operator=(const queue& other){
    if(this!=&other){
        m_queue=other.m_queue;
    }
    return *this;
}

template <typename T>
queue<T>& queue<T>::operator=(queue&& other){
    if(this!=&other){
        m_queue=std::move(other.m_queue);
    }
    return *this;
}

template <typename T>
std::size_t queue<T>::size(){
    return m_queue.size();
}

template <typename T>
bool queue<T>::empty(){
    return m_queue.empty();
}

template <typename T>
void queue<T>::push(const T& value){
    m_queue.push_back(value);
}

template <typename T>
void queue<T>::pop(){
    if(m_queue.size()==0) throw std::out_of_range("No element to delete");
    m_queue.erase(m_queue.begin());
}

template <typename T>
void queue<T>::clear(){
    m_queue.clear();
}

template <typename T>
T& queue<T>::front() {
    if (m_queue.empty()) throw std::out_of_range("Queue is empty");
    return m_queue.front();
}

template <typename T>
T& queue<T>::back() {
    if (m_queue.empty()) throw std::out_of_range("Queue is empty");
    return m_queue.back();
}


template <typename T>
const T& queue<T>::front()const{
    return m_queue.front();
}

template <typename T>
const T& queue<T>::back()const{
    return m_queue.back();
}