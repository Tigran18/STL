#include "deque.hpp"

using namespace my;

template <typename T>
std::size_t deque<T>::size()const{
    return m_size;
}