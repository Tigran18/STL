#pragma once
#include <vector>
#include <initializer_list>
#include <stdexcept>

namespace my {
    template <typename T>
    class stack {
    private:
        std::vector<T> m_stack;
    public:
        stack();

        stack(std::initializer_list<T> init);

        stack(const stack& other);

        stack(stack&& other) noexcept;

        stack& operator=(const stack& other);

        stack& operator=(stack&& other) noexcept;

        void push(const T& value);

        void pop();

        T top() const;

        std::size_t size() const;

        bool empty() const;
    };
}


#include "stack.tpp"