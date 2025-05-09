#pragma once
#include <memory>
#include <vector>
#include <utility>
#include <algorithm>

namespace my{
    template <typename T>
    class set{
        private:
            static constexpr bool red=true;
            static constexpr bool black=false;

            struct node{
                T data;
                bool color;
                node* rightnode=nullptr;
                node* leftnode=nullptr;
                node(const T& value, bool color);
            };
            node* root=nullptr;
            bool is_red(node* n)const;
            node* rotate_left(node* n);
            node* rotate_right(node* n);
            void flip_colors(node* h);
            node* insert(node* root, const T& value);
            std::size_t size=0;
            node* delete_node(node* n , const T& value);
            node* find_min(node* n);
            void delete_tree(node* n);
        public:
            set();

            template <typename ...Args>
            set(T data, Args ...args);

            set(const set& other);

            set(set&& other)noexcept;

            set& operator=(const set& other);

            set& operator=(set&& other)noexcept;

            void insert(const T& value);

            void remove(const T& value);

            ~set();

            bool contains(const T& value)const;

        class iterator {
            private:
                std::vector<node*> stack;
                void pushLeft(node* n);
    
            public:
                iterator(node* root);
    
                iterator& operator++();
    
                const T& operator*() const;
    
                const T* operator->() const;
    
                bool operator==(const iterator& other) const;
    
                bool operator!=(const iterator& other) const;
            };
            
            iterator begin() const;

            iterator end() const;

            iterator find(const T& value)const;

    };
}

#include "set.tpp"