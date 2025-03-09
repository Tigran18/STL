#include "single_linked_list.h"

using namespace my;

template <typename T>
typename single_linked_list<T>::iterator& single_linked_list<T>::iterator::operator++(){
    if(current){
        current=current->next;
    }
    return *this;
}

template <typename T>
bool single_linked_list<T>::iterator::operator!=(const iterator& other)const{
    return current!=other.current;
}

template <typename T>
T& single_linked_list<T>::iterator::operator*(){
    if(!current){
        throw std::out_of_range("Out of range");
    }
    return current->data;
}

template <typename T>
typename single_linked_list<T>::iterator single_linked_list<T>::begin(){ 
    return iterator(head); 
}

template <typename T>
typename single_linked_list<T>::iterator single_linked_list<T>::end(){ 
    return iterator(nullptr); 
}

template <typename T>
const typename single_linked_list<T>::iterator single_linked_list<T>::begin() const{
    return iterator(head);
}

template <typename T>
const typename single_linked_list<T>::iterator single_linked_list<T>::end() const{
    return iterator(nullptr);
}

template <typename T>
single_linked_list<T>::single_linked_list(std::initializer_list<T> init):head(nullptr), size(0){
    for(const T& value:init){
        insert_back(value);
    }
}

template <typename T>
void single_linked_list<T>::clear() {
    while (head) {
        node* temp = head;
        head = head->next;
        delete temp;
    }
    head = nullptr; 
    size = 0;
}

template <typename T>
single_linked_list<T>::~single_linked_list(){
    clear();
}

template <typename T>
void single_linked_list<T>::delete_at(const std::size_t k){
    if (!head || k >= size){
        throw std::out_of_range("Out of range");
    }
    if (k == 0) {
        node* temp = head;
        head = head->next;
        delete temp;
    } 
    else {
        node* temp = head;
        for (std::size_t i = 0; i < k - 1 && temp->next; i++) {
            temp = temp->next;
        }
        if (!temp->next) return; 

        node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    size--;
}

template <typename T>
void single_linked_list<T>::insert_back(T value) {
    node* new_node = new node(value);
    if (!head) {
        head = new_node;
    } else {
        node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    size++;
}

template <typename T>
T& single_linked_list<T>::operator[](const std::size_t k) {
    if(k>=size){
        throw std::out_of_range("Out of range");
    }
    if(k==0){
        return head->data;
    }
    node* temp=head;
    for(std::size_t i=0; i<k; i++){
        temp=temp->next;
    }
    return temp->data;
}

template <typename T>
typename single_linked_list<T>::iterator single_linked_list<T>::iterator::operator+(std::size_t k)const{
    iterator it = *this;
    while (k-- && it.current) {
        ++it;
    }
    return it;
}

template <typename T>
single_linked_list<T>::single_linked_list(const single_linked_list& other): head(nullptr), size(0) {
    for(auto it=other.begin(); it!=other.end(); ++it){
        insert_back(*it);
    }
}

template <typename T>
single_linked_list<T>::single_linked_list(single_linked_list&& other)noexcept: head(other.head), size(other.size){
    other.head=nullptr;
    other.size=0;
}

template <typename T>
std::size_t single_linked_list<T>::get_size()const{ 
    return size; 
}

template <typename T>
void single_linked_list<T>::insert_at(const iterator arg, T value){
    node* node_to_insert=new node(value);
    if(arg==begin()){
        node_to_insert->next=head;
        head=node_to_insert;
    }
    else{
        node* temp=head;
        node* prev=nullptr;
        for(auto it=begin(); it!=arg; ++it){
            prev=temp;
            temp=temp->next;
        }
        prev->next=node_to_insert;
        node_to_insert->next=temp;
    }
    size++;
}

template <typename T>
bool single_linked_list<T>::iterator::operator==(const iterator& other)const{
    return current==other.current;
}

template <typename T>
single_linked_list<T>::iterator::iterator(node* temp): current(temp){}

template <typename T>
single_linked_list<T>::node::node(T value): data(std::move(value)), next(nullptr){}

template <typename T>
single_linked_list<T>::single_linked_list(T value): head(new node(value)), size(1) {}