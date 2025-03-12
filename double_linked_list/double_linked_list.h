#pragma once

template <typenae T>
namespace my{
    class double_linked_list{
        private:
            node* head;
            node* tail;
            std::size_t size;
            struct node{
                T data;
                node* next;
                node* prev;
                node(T value);
            };
        public:
            class iterator{
                private:
                    node* current;
                public:
                    iterator(node* temp);
            };

            iterator begin();
            iterator end();
            iterator cbegin();
            iterator cend();
            iterator begin()const;
            iterator end()const;
            iterator cbegin()const;
            iterator cend() const;

            double_linked_list():head(nullptr), tail(nullptr), size(0){}

            double_linked_list(std::initializer_list<T> init):head(nullptr), tail(nullptr), size(0){
                for(auto& el : init){
                    insert_back(el);
                }
            }

            void insert_back(T value){
                node* new_node=new node(T);
                if(!head){
                    head=new_node;
                }
                else{
                    node* temp=head;
                    while(!tail){
                        node* temp_new=temp=temp;
                        temp=temp->next;
                        temp->prev=temp_new;
                    }
                    temp->next=new_node;
                }
                size++;
            }

            double_linked_list& operator[](std::size_t k){
                if()
            }
    };
}

#include "double_linked_list.tpp"