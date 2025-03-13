#pragma once

namespace my{
    template <typename T>
    class list{
        private:
        struct node{
            T data;
            node* next;
            node* prev;
            node(T value);
        };
        std::size_t size_l;
        node* head;
        node* tail;
        public:

        list();
        list(std::initializer_list<T> init);
        void insert_back(const T& value);
        ~list();
        void clear();

        std::size_t size()const;

        list(const list& other);

        list(list&& other)noexcept;

        class iterator{
            private:
            node* current;

            public:            
            iterator(node* temp);
            T& operator*();
            iterator& operator++();
            bool operator!=(const iterator& other)const;
            iterator operator+(std::size_t k)const{
                iterator it = *this;
                while (k-- && it.current) {
                    ++it;
                }
                return it;
            }
            bool operator==(const iterator& other)const{
                return current==other.current;
            }
        };

        iterator begin();
        iterator end();
        iterator begin()const;
        iterator end()const;

        class reverse_iterator{
            private:
            node* current;
            public:

            reverse_iterator(node* temp);
            T& operator*();
            reverse_iterator& operator++();
            bool operator!=(const reverse_iterator& other)const;
        };

        reverse_iterator rbegin();
        reverse_iterator rend();
        reverse_iterator rbegin()const;
        reverse_iterator rend()const;

        void insert_at(const iterator& arg, const T value){
            node* new_node=new node(value);
            if(arg==begin()){
                new_node->next=head->next;
                head->next->prev=new_node;
                head=new_node;
                head->prev=nullptr;
                size_l++;
                return;
            }
            node* temp=head;
            for(auto it=begin(); it!=arg; ++it){
                temp=temp->next;
            }
            temp->next->prev=new_node;
            new_node->prev=temp;
            size_l++;
        }

        void delete_at(const std::size_t k){
            if(k>=size_l){
                throw std::out_of_range("Out of size.");
            }
            node* temp=head;
            if (k == 0) {
                head = head->next;
                if (head) {
                    head->prev = nullptr;
                } else {
                    tail = nullptr;
                }
                delete temp;
                size_l--;
                return;
            }
            for(std::size_t i=0; i<k-1; i++){
                temp=temp->next;
            }
            node* node_to_delete=temp->next;
            temp->next=node_to_delete->next;
            if (node_to_delete->next) {
                node_to_delete->next->prev = temp;
            } else {
                tail = temp;
            }
            size_l--;
        }

        T& operator[](const std::size_t k)const;
    };
}

#include "list.tpp"