#include "stack.hpp"

using namespace my;

template <typename T>
stack<T>::stack() = default;

template <typename T>
stack<T>::stack(std::initializer_list<T> init) : m_stack(init), m_size(init.size()) {}

template <typename T>
stack<T>::stack(stack&& other) noexcept : m_stack(std::move(other.m_stack)), m_size(other.m_size) {
    other.m_size = 0;
}

template <typename T>
stack<T>& stack<T>::operator=(const stack& other) {
    if (this != &other) {
        m_stack = other.m_stack;
        m_size = other.m_size;
    }
    return *this;
}

template <typename T>
stack<T>& stack<T>::operator=(stack&& other) noexcept {
    if (this != &other) {
        m_stack = std::move(other.m_stack);
        m_size = other.m_size;
        other.m_size = 0;
    }
    return *this;
}

template <typename T>
void stack<T>::push(const T& value){
    m_stack.push_back(value);
    ++m_size;
}

template <typename T>
void stack<T>::pop(){
    if (m_size == 0) throw std::out_of_range("No element.");
    m_stack.pop_back();
    --m_size;
}

template <typename T>
T stack<T>::top() const {
    if (m_size == 0) throw std::out_of_range("No element.");
    return m_stack.back();
}

template <typename T>
std::size_t stack<T>::size() const {
    return m_size;
}

template <typename T>
bool stack<T>::empty() const {
    return m_size == 0;
}