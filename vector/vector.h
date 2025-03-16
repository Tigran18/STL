#pragma once
#include <initializer_list>
#include <algorithm>
#include <cstddef>

namespace my {
    template <typename T>
    class vector {
    private:
        T* m_ptr = nullptr;
        std::size_t m_size = 0;
        std::size_t m_cap = 0;

        void reallocate(std::size_t new_cap) {
            T* new_ptr = new T[new_cap];
            for (std::size_t i = 0; i < m_size; ++i) {
                new_ptr[i] = std::move(m_ptr[i]);
            }
            delete[] m_ptr;
            m_ptr = new_ptr;
            m_cap = new_cap;
        }

    public:
        vector() = default;

        vector(std::initializer_list<T> args) : vector() {
            for (const T& arg : args) {
                push_back(arg);
            }
        }

        void clear(){
            delete[] m_ptr;
        }

        ~vector() {
            clear();
        }

        void push_back(const T& arg) {
            if (m_size == m_cap) {
                reallocate(m_cap == 0 ? 1 : 2 * m_cap);
            }
            m_ptr[m_size++] = arg;
        }

        T& operator[](std::size_t k) {
            return m_ptr[k];
        }

        const T& operator[](std::size_t k) const {
            return m_ptr[k];
        }

        std::size_t size() const {
            return m_size;
        }

        std::size_t capacity() const {
            return m_cap;
        }

        vector(const vector& other) : m_ptr(new T[other.m_cap]), m_size(other.m_size), m_cap(other.m_cap) {
            for (std::size_t i = 0; i < m_size; ++i) {
                m_ptr[i] = other.m_ptr[i];  // Copy each element
            }
        }

        class iterator {
            // TODO: Implement iterator class
        };
    };
}
