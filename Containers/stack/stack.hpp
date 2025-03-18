#pragma once
#include <vector>
#include <initializer_list>
#include <stdexcept>

namespace my {
    template <typename T>
    class stack {
    private:
        std::vector<T> m_stack;
        std::size_t m_size = 0;

    public:
        stack() = default;

        stack(std::initializer_list<T> init) : m_stack(init), m_size(init.size()) {}

        stack(const stack& other) = default;

        stack(stack&& other) noexcept : m_stack(std::move(other.m_stack)), m_size(other.m_size) {
            other.m_size = 0;
        }

        stack& operator=(const stack& other) {
            if (this != &other) {
                m_stack = other.m_stack;
                m_size = other.m_size;
            }
            return *this;
        }

        stack& operator=(stack&& other) noexcept {
            if (this != &other) {
                m_stack = std::move(other.m_stack);
                m_size = other.m_size;
                other.m_size = 0;
            }
            return *this;
        }

        void push(const T& value) {
            m_stack.push_back(value);
            ++m_size;
        }

        void pop() {
            if (m_size == 0) throw std::out_of_range("No element.");
            m_stack.pop_back();
            --m_size;
        }

        T top() const {
            if (m_size == 0) throw std::out_of_range("No element.");
            return m_stack.back();
        }

        std::size_t size() const {
            return m_size;
        }

        bool empty() const {
            return m_size == 0;
        }
    };
}
