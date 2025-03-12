#include "list.h"

using namespace my;

template <typename T>
list<T>::node::node(T value):data(std::move(value)), next(nullptr), prev(nullptr){}

template <typename T>
list<T>::list():head(nullptr), tail(nullptr), size(0){

}

template <typename T>
list<T>::list(std::initializer_list<T> init):head(nullptr), tail(nullptr), size(0){
    for(const auto& el : init){
        insert_back(el);
    }
}

template <typename T>
void list<T>::insert_back(const T& value){
    node* new_node=new node(value);
    if(!head){
        head=new_node;
        tail=new_node;
    }
    else{
        tail->next=new_node;
        new_node->prev=tail;
        tail=new_node;
    }
    size++;
}

template <typename T>
list<T>::~list(){
    clear();
}

template <typename T>
void list<T>::clear(){
    while(head){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    head=nullptr;
    size=0;
}

template <typename T>
list<T>::iterator::iterator(node* temp):current(temp){}

template <typename T>
T& list<T>::iterator::operator*(){
    return current->data; 
}

template <typename T>
list<T>::iterator& list<T>::iterator::operator++(){
    if(current){
        current=current->next;
    }
    return *this;
}

template <typename T>
bool list<T>::iterator::operator!=(const iterator& other)const{
    return current!=other.current;
}

template <typename T>
list<T>::reverse_iterator::reverse_iterator(node* temp):current(temp){}

template <typename T>
T& list<T>::reverse_iterator::operator*(){
    return current->data; 
}

template <typename T>
list<T>::reverse_iterator& list<T>::reverse_iterator::operator++(){
    if(current){
        current=current->prev;
    }
    return *this;
}

template <typename T>
bool list<T>::reverse_iterator::operator!=(const reverse_iterator& other)const{
    return current!=other.current;
}

template <typename T>
list<T>::iterator list<T>::begin(){
    return iterator(head);
}

template <typename T>
list<T>::iterator list<T>::end(){
    return iterator(nullptr);
}

template <typename T>
list<T>::iterator list<T>::begin()const{
    return iterator(head);
}

template <typename T>
list<T>::iterator list<T>::end()const{
    return iterator(nullptr);
}

template <typename T>
list<T>::reverse_iterator list<T>::rbegin(){
    return reverse_iterator(tail);
}

template <typename T>
list<T>::reverse_iterator list<T>::rend(){
    return reverse_iterator(nullptr);
}

template <typename T>
list<T>::reverse_iterator list<T>::rbegin()const{
    return reverse_iterator(tail);
}

template <typename T>
list<T>::reverse_iterator list<T>::rend()const{
    return reverse_iterator(nullptr);
}