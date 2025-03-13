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