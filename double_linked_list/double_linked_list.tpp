#include "double_linked_list.h"

using namespace my;

template <typename T>
double_linked_list<T>::node::node(T value):data(std::move(value)), next(nullptr), prev(nullptr){}

template <typename T>
double_linked_list<T>::iterator::iterator(node* temp):current(node){}

template <typename T>
double_linked_list<T>::iterator::begin(){
    return iterator(head);
}

template <typename T>
double_linked_list<T>::iterator::begin()const{
    return iterator(head);
}


template <typename T>
double_linked_list<T>::iterator::end(){
    return iterator(tail);
}

template <typename T>
double_linked_list<T>::iterator::end()const{
    return iterator(tail);
}


template <typename T>
double_linked_list<T>::iterator::cbegin(){
    return iterator(tail);
}

template <typename T>
double_linked_list<T>::iterator::cbegin()const{
    return iterator(tail);
}


template <typename T>
double_linked_list<T>::iterator::cend(){
    return iterator(head);
}

template <typename T>
double_linked_list<T>::iterator::cend()const{
    return iterator(head);
}