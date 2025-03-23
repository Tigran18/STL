#pragma once
#include <memory>
#include <utility>
#include <vector>

namespace my{
    template <typename T>
    class deque{
        private:
            std::vector<T> m_vec={};
            std::size_t m_size=0;
        public:
            deque();

            deque(std::initializer_list<T> init);

            deque(const deque& other);

            deque(deque&& other)noexcept;

            deque& operator=(const deque& other);

            deque& operator=(deque&& other)noexcept;

            void push_back(){}

            void push_front(){}

            void pop_back(){
            }

            void pop_front(){
            }
        
            T front()const;

            T back()const;

            std::size_t size() const;
    };
}

#include "deque.tpp"