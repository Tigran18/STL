#include "set.hpp"

using namespace my;

template <typename T>
set<T>::set():data(0), rightnode(nullptr), leftnode(nullptr){}

template <typename T>
template <typename ...Args>
set<T>::set(T value, Args ...args):data(value), rightnode(nullptr), leftnode(nullptr){
    (insert(args), ...);
}

template <typename T>
set<T>* set<T>::insert(const T& value){
    if(value==data){
        return this;
    }
    else if(value>data){
        if(!rightnode){
            rightnode=new set(value);
        }
        else{
            rightnode->insert(value);
        }
    }
    else{
        if(!leftnode){
            leftnode=new set(value);
        }
        else{
            leftnode->insert(value);
        }
    }
    return this;
}

template <typename T>
set<T>::set(const set& other)=default;

template <typename T>
set<T>::set(set&& other)noexcept{
}

template <typename T>
set<T>& set<T>::operator=(const set& other){
    if(this!=&other){
        
    }
    return *this;
}

template <typename T>
set<T>& set<T>::operator=(set&& other)noexcept{
    if(this!=&other){
    }
    return *this;
}

template <typename T>
auto set<T>::begin(){
}

template <typename T>
auto set<T>::begin()const{
}

template <typename T>
auto set<T>::end(){
}

template <typename T>
auto set<T>::end()const{
}

template <typename T>
bool set<T>::empty() const{
}

template <typename T>
auto set<T>::find(const T& data)const{
    
}

template <typename T>
std::size_t set<T>::size()const{
}

template <typename T>
void set<T>::erase(const T& data){
    
}
