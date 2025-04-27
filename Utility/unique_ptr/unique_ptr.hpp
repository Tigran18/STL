#pragma once

namespace my{
    template <typename T>
    class unique_ptr {
        private:
            T* ptr;
        public:
            unique_ptr(T* p=nullptr):ptr(p){}

            unique_ptr(const unique_ptr& other)=delete;

            unique_ptr& operator=(const unique_ptr& other)=delete;

            unique_ptr(unique_ptr&& other)noexcept:ptr(other.ptr){
                other.ptr=nullptr;
            }

            unique_ptr& operator=(unique_ptr&& other){
                if(*this!=other){
                    ptr=other.ptr;
                    other.ptr=nullptr;
                }
                return *this;
            }

            T& operator*()const{
                return *ptr;
            }

            T& operator[](std::size_t k)const {
                return ptr[k];
            }

            unique_ptr& operator+(const std::size_t& k)const{
                return ptr+k;
            }
    };

    template <typename T>
    class unique_ptr<T[]> {
        private:
            T* ptr;
        public:
            unique_ptr(T* p=nullptr):ptr(p){}

            unique_ptr(const unique_ptr& other)=delete;

            unique_ptr& operator=(const unique_ptr& other)=delete;

            unique_ptr(unique_ptr&& other)noexcept:ptr(other.ptr){
                other.ptr=nullptr;
            }

            unique_ptr& operator=(unique_ptr&& other){
                if(*this!=other){
                    ptr=other.ptr;
                    other.ptr=nullptr;
                }
                return *this;
            }

            T& operator*()const{
                return *ptr;
            }

            T& operator[](std::size_t k)const {
                return ptr[k];
            }

            unique_ptr& operator+(const std::size_t& k)const{
                return ptr+k;
            }
    };
}

#include "unique_ptr.tpp"