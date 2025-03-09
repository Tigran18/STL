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
bool single_linked_list<T>::iterator::operator!=(const iterator& other){
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
    } else {
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
    if(k<0 ||k>size){
        throw std::out_of_range("Out of range");
    }
    node* temp=head;
    for(std::size_t i=0; i<k; i++){
        temp=temp->next;
    }
    return temp->data;
}