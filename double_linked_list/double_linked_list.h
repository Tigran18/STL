#pragma once

namespace my{
template <typename T>
    class double_linked_list{
        private:
        struct node{
            T data;
            node* next;
            node* prev;
            node(T value);
        };
            node* head;
            node* tail;
            std::size_t size;
            
        public:
            class iterator{
                private:
                    node* current;
                public:
                    iterator(node* temp);
            };

            iterator begin();
            iterator end();
            iterator rbegin();
            iterator rend();
            iterator begin()const;
            iterator end()const;
            iterator rbegin()const;
            iterator rend() const;

            double_linked_list():head(nullptr), tail(nullptr), size(0){}

            double_linked_list(std::initializer_list<T> init):head(nullptr), tail(nullptr), size(0){
                for(auto& el : init){
                    insert_back(el);
                }
            }

            void insert_back(T value) {
                node* new_node = new node(value);
                if (!head) {
                    head = new_node;
                    tail = new_node;
                } else {
                    tail->next = new_node;
                    new_node->prev = tail;
                    tail = new_node;
                }
                size++;
            }            

            ~double_linked_list(){
                clear();
            }

            void clear(){
                while(head){
                    node* temp=head;
                    head=head->next;
                    delete temp;
                }
                head=nullptr;
                size=0;
            }

            T& operator[](std::size_t k) {
                if (k >= size) {
                    throw std::out_of_range("Index out of range");
                }
                if(k==0){
                    return head->data;
                }
                node* temp = head;
                while (k--) {
                    temp = temp->next;
                }
                return temp->data;
            }
            
            const T& operator[](std::size_t k) const {
                if (k >= size) {
                    throw std::out_of_range("Index out of range");
                }
                node* temp = head;
                while (k--) {
                    temp = temp->next;
                }
                return temp->data;
            }
            
    };
}

#include "double_linked_list.tpp"