#pragma once

namespace my{
    template <typename T>
    class forward_list{
        private:
        struct node{
            T data;
            node* next;
            node(T value);
        };
        node* m_head;
        std::size_t m_size;

        public:
        
        forward_list();

        forward_list(std::initializer_list<T> init);

        forward_list(const forward_list& other);
        
        forward_list(forward_list&& other) noexcept;

        forward_list& operator=(const forward_list& other);

        forward_list& operator=(forward_list&& other)noexcept;
        
        ~forward_list();

        void clear();

        void delete_at(const std::size_t k);

        std::size_t get_size() const;

        void insert_back(T value);

        T& operator[](const std::size_t k);

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

        void insert_at(const iterator& arg, T value);

    };
}

#include "forward_list.tpp"
