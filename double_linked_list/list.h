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
        std::size_t size;
        node* head;
        node* tail;
        public:

        list();
        list(std::initializer_list<T> init);
        void insert_back(const T& value);
        ~list();
        void clear();

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

        T& operator[](const std::size_t k)const{
            if(k>=size){
                throw std::out_of_range("Out of range.");
            }
            std::size_t i=k;
            for(auto it=begin(); it!=end(); ++it){
                if(i==0){
                    return *it;
                }
                i--;
            }
        }
    };
}

#include "list.tpp"