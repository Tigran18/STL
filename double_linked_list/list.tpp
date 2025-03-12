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
list<T>::clear(){
    while(head){
        node* temp=head;
        head=head->next;
        delete temp;
    }
    head=nullptr;
    size=0;
}