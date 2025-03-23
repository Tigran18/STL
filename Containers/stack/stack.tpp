#include "stack.hpp"

using namespace my;

template <typename T>
stack<T>::stack():m_stack({}){}

template <typename T>
stack<T>::stack(std::initializer_list<T> init):stack(){
    for(auto& el : init){
        m_stack.push_back(el);
    }
}

template <typename T>
stack<T>::stack(const stack& other) = default;

template <typename T>
stack<T>::stack(stack&& other) noexcept{
    m_stack=std::move(other.m_stack);
}

template <typename T>
stack<T>& stack<T>::operator=(const stack& other) {
    if (this != &other) {
        m_stack = other.m_stack;
    }
    return *this;
}

template <typename T>
stack<T>& stack<T>::operator=(stack&& other) noexcept {
    if (this != &other) {
        m_stack = std::move(other.m_stack);
    }
    return *this;
}

template <typename T>
void stack<T>::push(const T& value){
    m_stack.push_back(value);
}

template <typename T>
void stack<T>::pop(){
    if (m_stack.size() == 0) throw std::out_of_range("No element.");
    m_stack.pop_back();
}

template <typename T>
T stack<T>::top() const {
    if (m_stack.size() == 0) throw std::out_of_range("No element.");
    return m_stack.back();
}

template <typename T>
std::size_t stack<T>::size() const {
    return m_stack.size();
}

template <typename T>
bool stack<T>::empty() const {
    return m_stack.size()==0;
}

