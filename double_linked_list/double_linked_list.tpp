#include "double_linked_list.h"

using namespace my;

template <typename T>
double_linked_list<T>::node::node(T value):data(std::move(value)), next(nullptr), prev(nullptr){}

template <typename T>
double_linked_list<T>::iterator::iterator(node* temp):current(temp){}

template <typename T>
double_linked_list<T>::iterator double_linked_list<T>::begin(){
    return iterator(head);
}

template <typename T>
double_linked_list<T>::iterator double_linked_list<T>::begin()const{
    return iterator(head);
}


template <typename T>
double_linked_list<T>::iterator double_linked_list<T>::end(){
    return iterator(nullptr);
}

template <typename T>
double_linked_list<T>::iterator double_linked_list<T>::end()const{
    return iterator(nullptr);
}


template <typename T>
double_linked_list<T>::iterator double_linked_list<T>::rbegin(){
    return iterator(tail);
}

template <typename T>
double_linked_list<T>::iterator double_linked_list<T>::rbegin()const{
    return iterator(tail);
}


template <typename T>
double_linked_list<T>::iterator double_linked_list<T>::rend(){
    return iterator(nullptr);
}

template <typename T>
double_linked_list<T>::iterator double_linked_list<T>::rend()const{
    return iterator(nullptr);
}