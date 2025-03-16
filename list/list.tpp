#include "list.h"

using namespace my;

template <typename T>
list<T>::node::node(T value):data(std::move(value)), next(nullptr), prev(nullptr){}

template <typename T>
list<T>::list():head(nullptr), tail(nullptr), size_l(0){}

template <typename T>
list<T>::list(std::initializer_list<T> init):list(){
    for(const auto& el : init){
        insert_back(el);
    }
}

template <typename T>
list<T>::list(const list& other):head(nullptr), tail(nullptr), size_l(0){
    for(auto it=other.begin(); it!=other.end(); ++it){
        insert_back(*it);
    }
}

template <typename T>
list<T>::list(list&& other)noexcept:head(other.head), tail(other.tail), size_l(other.size_l){
    other.head=nullptr;
    other.tail=nullptr;
    other.size_l=0;
}

template <typename T>
list<T>& list<T>::operator=(const list& other){
    if(this!=&other){
        clear();
        for(auto it=other.begin(); it!=other.end(); ++it){
            insert_back(*it);
        }
    }
    return *this;
}

template <typename T>
list<T>& list<T>::operator=(list&& other)noexcept{
    if(this!=&other){
        clear();
        head=other.head;
        tail=other.tail;
        size_l=other.size_l;
        other.head=nullptr;
        other.tail=nullptr;
        other.size_l=0;
    }
    return *this;
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
    size_l++;
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
    size_l=0;
}

template <typename T>
list<T>::iterator::iterator(node* temp):current(temp){}

template <typename T>
T& list<T>::iterator::operator*(){
    return current->data; 
}

template <typename T>
typename list<T>::iterator& list<T>::iterator::operator++(){
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
typename list<T>::reverse_iterator& list<T>::reverse_iterator::operator++(){
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
typename list<T>::iterator list<T>::begin(){
    return iterator(head);
}

template <typename T>
typename list<T>::iterator list<T>::end(){
    return iterator(nullptr);
}

template <typename T>
typename list<T>::iterator list<T>::begin()const{
    return iterator(head);
}

template <typename T>
typename list<T>::iterator list<T>::end()const{
    return iterator(nullptr);
}

template <typename T>
typename list<T>::reverse_iterator list<T>::rbegin(){
    return reverse_iterator(tail);
}

template <typename T>
typename list<T>::reverse_iterator list<T>::rend(){
    return reverse_iterator(nullptr);
}

template <typename T>
typename list<T>::reverse_iterator list<T>::rbegin()const{
    return reverse_iterator(tail);
}

template <typename T>
typename list<T>::reverse_iterator list<T>::rend()const{
    return reverse_iterator(nullptr);
}

template <typename T>
T& list<T>::operator[](const std::size_t k)const{
    if(k>=size_l){
        throw std::out_of_range("Out of range.");
    }
    auto it=begin();
    for(std::size_t i=0; i<k; i++){
        ++it;
    }
    return *it;
}

template <typename T>
std::size_t list<T>::size()const{
    return size_l;
}

template <typename T>
void list<T>::insert_at(const iterator& arg, T value){
    node* node_to_insert=new node(value);
    if(arg==begin()){
        if (head) {
            node_to_insert->next = head;
            head->prev = node_to_insert;
        } else {
            tail = node_to_insert;
        }
        head = node_to_insert;
        
    }
    else if(arg==end()){
        node_to_insert->prev=tail;
        tail->next=node_to_insert;
        tail=node_to_insert;
    }
    else{
        node* temp=head;
        for(auto it=begin(); it!=arg; ++it){
            temp=temp->next;
        }
        temp=temp->prev;
        node* node_after_inserted=temp->next;
        temp->next=node_to_insert;
        node_to_insert->next=node_after_inserted;
        node_after_inserted->prev=node_to_insert;
        node_to_insert->prev=temp;
    }
    ++size_l;
}

template <typename T>
void list<T>::delete_at(const std::size_t& k){
    if(k>=size_l){
        throw std::out_of_range("Out of range.");
    }
    if(k==0){
        node* node_to_delete=head;
        head=head->next;
        delete node_to_delete;
        head->prev=nullptr;
    }
    else if(size_l==1){
        node* node_to_delete=head;
        delete node_to_delete;
        head=tail=nullptr;
    }
    else if(k==size_l-1){
        node* node_to_delete=tail;
        tail=tail->prev;
        delete node_to_delete;
        tail->next=nullptr;
    }
    else{
        node* temp=head;
        for(std::size_t i=0; i<k-1; i++){
            temp=temp->next;
        }
        node* node_to_delete=temp->next;
        node* node_after_temp=node_to_delete->next;
        temp->next=node_after_temp;
        node_after_temp->prev=temp;
        delete node_to_delete;
    }
    --size_l;
}