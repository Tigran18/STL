#pragma once
#include <memory>
#include <utility>

namespace my{
    class string{
        private:
            char* m_ptr=nullptr;
            std::size_t m_size{};
            std::size_t m_cap{};
            void reallocate(std::size_t new_cap){
                char* new_ptr=new char[new_cap];
                for(std::size_t i=0; i<m_size; i++){
                    new_ptr[i]=m_ptr[i];
                }
                delete[] m_ptr;
                m_ptr=new_ptr;
                m_cap=new_cap;
            }
        public:
            string():m_ptr(nullptr), m_size(0), m_cap(0){

            }

            string(std::initializer_list<char> init):string(){
                for(auto& el : init){
                    push_back(el);
                }
            }

            void push_back(char c){
                if(m_size==m_cap){
                    reallocate(m_cap==0?1:m_cap*2);
                }
                m_ptr[m_size++]=c;
    };
}