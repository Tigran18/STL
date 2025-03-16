#include "forward_list.h"

using namespace my;

template <typename T>
forward_list<T>::forward_list():m_head(nullptr), m_size(0){}

template <typename T>
forward_list<T>::forward_list(std::initializer_list<T> init):forward_list(){
    for(const T& value:init){
        insert_back(value);
    }
}

template <typename T>
forward_list<T>::forward_list(const forward_list& other): m_head(nullptr), m_size(0) {
    for(auto it=other.begin(); it!=other.end(); ++it){
        insert_back(*it);
    }
}

template <typename T>
forward_list<T>::forward_list(forward_list&& other)noexcept: m_head(other.m_head), m_size(other.m_size){
    other.m_head=nullptr;
    other.m_size=0;
}

template <typename T>
forward_list<T>& forward_list<T>::operator=(const forward_list& other){
    if(this!=&other){
        clear();
        for(auto it=other.begin(); it!=other.end(); ++it){
            insert_back(*it);
        }
    }
    return *this;
}

template <typename T>
forward_list<T>& forward_list<T>::operator=(forward_list&& other)noexcept{
    if(this!=&other){
        clear();
        for(auto it=other.begin(); it!=other.end(); ++it){
            insert_back(*it);
        }
        other.m_head=nullptr;
        other.m_size=0;
    }
    return *this;
}

template <typename T>
typename forward_list<T>::iterator& forward_list<T>::iterator::operator++(){
    if(current){
        current=current->next;
    }
    return *this;
}

template <typename T>
bool forward_list<T>::iterator::operator!=(const iterator& other)const{
    return current!=other.current;
}

template <typename T>
T& forward_list<T>::iterator::operator*(){
    if(!current){
        throw std::out_of_range("Out of range");
    }
    return current->data;
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::begin(){ 
    return iterator(m_head); 
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::end(){ 
    return iterator(nullptr); 
}

template <typename T>
const typename forward_list<T>::iterator forward_list<T>::begin() const{
    return iterator(m_head);
}

template <typename T>
const typename forward_list<T>::iterator forward_list<T>::end() const{
    return iterator(nullptr);
}

template <typename T>
void forward_list<T>::clear() {
    while (m_head) {
        node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    }
    m_head = nullptr; 
    m_size = 0;
}

template <typename T>
forward_list<T>::~forward_list(){
    clear();
}

template <typename T>
void forward_list<T>::delete_at(const std::size_t k){
    if (!m_head || k >= m_size){
        throw std::out_of_range("Out of range");
    }
    if (k == 0) {
        node* temp = m_head;
        m_head = m_head->next;
        delete temp;
    } 
    else {
        node* temp = m_head;
        for (std::size_t i = 0; i < k - 1 && temp->next; i++) {
            temp = temp->next;
        }
        if (!temp->next) return; 

        node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next;
        delete nodeToDelete;
    }
    m_size--;
}

template <typename T>
void forward_list<T>::insert_back(T value) {
    node* new_node = new node(value);
    if (!m_head) {
        m_head = new_node;
    } else {
        node* temp = m_head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = new_node;
    }
    m_size++;
}

template <typename T>
T& forward_list<T>::operator[](const std::size_t k) {
    if(k>=m_size){
        throw std::out_of_range("Out of range");
    }
    if(k==0){
        return m_head->data;
    }
    node* temp=m_head;
    for(std::size_t i=0; i<k; i++){
        temp=temp->next;
    }
    return temp->data;
}

template <typename T>
typename forward_list<T>::iterator forward_list<T>::iterator::operator+(std::size_t k)const{
    iterator it = *this;
    while (k-- && it.current) {
        ++it;
    }
    return it;
}

template <typename T>
std::size_t forward_list<T>::get_size()const{ 
    return m_size; 
}

template <typename T>
void forward_list<T>::insert_at(const iterator& arg, T value){
    node* node_to_insert=new node(value);
    if(arg==begin()){
        node_to_insert->next=m_head;
        m_head=node_to_insert;
    }
    else{
        node* temp=m_head;
        node* prev=nullptr;
        for(auto it=begin(); it!=arg; ++it){
            prev=temp;
            temp=temp->next;
        }
        prev->next=node_to_insert;
        node_to_insert->next=temp;
    }
    m_size++;
}

template <typename T>
bool forward_list<T>::iterator::operator==(const iterator& other)const{
    return current==other.current;
}

template <typename T>
forward_list<T>::iterator::iterator(node* temp): current(temp){}

template <typename T>
forward_list<T>::node::node(T value): data(std::move(value)), next(nullptr){}