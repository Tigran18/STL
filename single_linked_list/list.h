#pragma once

namespace my{
    template <typename T>
    class single_list{
        public:
        struct node{
            T data;

            node* next;

            node():data(0), next(nullptr){}

            node(T value): data(std::move(value)), next(nullptr){}
        };

        class iterator{
            private:
            node* current;
            public:
            iterator(node* temp): current(temp){}

            iterator& operator++(){
                if(current){
                    current=current->next;
                }
                return *this;
            }
            
            bool operator!=(const iterator& other){
                return current!=other.current;
            }

            T& operator*(){
                if(!current){
                    throw std::out_of_range("Out of range");
                }
                return current->data;
            }
        };

        iterator begin(){
            return iterator(head);
        };

        iterator end(){
            return iterator(nullptr);
        };

        single_list():head(nullptr), size(0){};

        single_list(T value): head(value), size(0){}

        single_list(std::initializer_list<T> init):head(nullptr), size(0){
            for(const T& value:init){
                insert_back(value);
            }
        }

        ~single_list(){
            node* temp=head;
            while(temp->next){
                node* next=temp->next;
                delete temp;
                temp=next;
            }

        }

        std::size_t get_size(){
            return size;
        }

        void insert_back(T value){
            node* new_node=new node(value);
            if(!head){
                head=new_node;
            }
            else{
                node* temp=head;
                while(temp->next){
                    temp=temp->next;
                }
                temp->next=new_node;
            }
            size++;
        }
        private:
        node* head;
        std::size_t size;
    };
}