#pragma once

namespace my{
    template <typename T>
    class single_list{
        public:
        struct node{
            T data;
            node* next;
            node(T value): data(std::move(value)), next(nullptr){}
        };

        class iterator{
            private:
            node* current;
            public:
            iterator(node* temp): current(temp){}
            iterator& operator++();
            bool operator!=(const iterator& other);
            T& operator*();
        };

        iterator begin();
        iterator end();

        const iterator begin() const;

        const iterator end() const;

        single_list():head(nullptr), size(0){}

        single_list(T value): head(new node(value)), size(1) {}

        single_list(std::initializer_list<T> init);

        single_list(const single_list& other) : head(nullptr), size(0) {
            for(auto it=other.begin(); it!=other.end(); ++it){
                insert_back(*it);
            }
        }
        
        single_list(single_list&& other) noexcept: head(other.head), size(other.size){
            other.head=nullptr;
            other.size=0;
        }
        
        ~single_list();

        void clear();

        void delete_at(const std::size_t k);

        std::size_t get_size() const { return size; }

        void insert_back(T value);

        private:
        node* head;
        std::size_t size;
    };
}

#include "list.tpp"