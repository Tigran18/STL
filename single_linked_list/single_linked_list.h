#pragma once

namespace my{
    template <typename T>
    class single_linked_list{
        public:
        struct node{
            T data;
            node* next;
            node(T value);
        };

        class iterator{
            private:
            node* current;
            public:
            iterator(node* temp);
            iterator& operator++();
            bool operator!=(const iterator& other)const;
            T& operator*();
            iterator operator+(std::size_t k) const;
            bool operator==(const iterator& other)const;
        };

        iterator begin();
        iterator end();

        const iterator begin() const;

        const iterator end() const;

        single_linked_list():head(nullptr), size(0){}

        single_linked_list(T value);

        single_linked_list(std::initializer_list<T> init);

        single_linked_list(const single_linked_list& other);
        
        single_linked_list(single_linked_list&& other) noexcept;
        
        ~single_linked_list();

        void clear();

        void delete_at(const std::size_t k);

        std::size_t get_size() const;

        void insert_back(T value);

        T& operator[](const std::size_t k);

        void insert_at(const iterator arg, T value);
 
        private:
        node* head;
        std::size_t size;
    };
}

#include "single_linked_list.tpp"