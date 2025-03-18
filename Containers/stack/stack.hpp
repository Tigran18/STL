#pragma once
#include <memory>
#include <utility>
#include <vector>
#include <initializer_list>

namespace my{
    template <typename T>
    class stack{
        private:
        std::vector<T> m_stack;
        std::size_t m_size=0;

        public:
        stack():m_stack({}), m_size(0){}

        stack(std::initializer_list<T> init):stack(){
            for(auto& arg : init){
                m_stack.push_back(arg);
                ++m_size;
            }
        }

        stack(const stack& other):m_stack(other.m_stack), m_size(other.m_size){
        }

        stack(stack&& other)noexcept:m_stack(other.m_stack), m_size(other.m_size){
            while(other.m_stack.size()!=0){
                other.top();
            }
            other.m_size=0;
        }

        void push_back(T value){
            m_stack.push_back(value);
            ++m_size;
        }

        T top(){
            if(m_size!=0){
                T value=m_stack[m_stack.size()-1];
                m_stack.erase(m_stack.begin()+m_stack.size()-1);
                --m_size;
                return value;
            }
            else{
                throw std::out_of_range("No element.");
            }
        }
    };
}