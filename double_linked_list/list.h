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
            iterator(node* temp):current(temp){}

            T& operator*(){
                return current->data; 
            }

            iterator& operator++(){
                if(current){
                    current=current->next;
                }
                return *this;
            }

            bool operator!=(const iterator& other){
                return current!=other.current;
            }
        };

        class reverse_iterator{
            private:
            node* current;

            public:

            reverse_iterator(node* temp):current(temp){}

            T& operator*(){
                return current->data; 
            }

            reverse_iterator& operator++(){
                if(current){
                    current=current->prev;
                }
                return *this;
            }

            bool operator!=(const reverse_iterator& other){
                return current!=other.current;
            }
        };


        iterator begin(){
            return iterator(head);
        }

        iterator end(){
            return iterator(nullptr);
        }

        iterator begin()const{
            return iterator(head);
        }

        iterator end()const{
            return iterator(nullptr);
        }

        reverse_iterator rbegin(){
            return reverse_iterator(tail);
        }

        reverse_iterator rend(){
            return reverse_iterator(nullptr);
        }

        reverse_iterator rbegin()const{
            return reverse_iterator(tail);
        }

        reverse_iterator rend()const{
            return reverse_iterator(nullptr);
        }
    };
}

#include "list.tpp"