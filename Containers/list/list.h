#pragma once
#include <utility>
#include <memory>

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

        list(const list& other);

        list(list&& other)noexcept;

        list& operator=(const list& other);

        list& operator=(list&& other)noexcept;
        
        void insert_back(const T& value);

        ~list();
        
        void clear();

        std::size_t size()const;

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

        void insert_at(const iterator& args, T value);
        
        void delete_at(const std::size_t& k);

        T& operator[](const std::size_t k)const;
    };
}

#include "list.tpp"