#pragma once
#include <iostream>
#include <cstring> 

namespace my {

    class string {
    private:
        char* m_ptr = nullptr;
        std::size_t m_size = 0;
        std::size_t m_cap = 0;

        void reallocate(std::size_t new_cap);

    public:
        string();

        string(const char* init);

        string(const string& other);

        string(string&& other) noexcept;

        string& operator=(const string& other);

        string& operator=(string&& other) noexcept;

        void push_back(const char c);

        friend std::ostream& operator<<(std::ostream& os, const string& str);

        friend string operator+(const string& lhs, const string& rhs);

        std::size_t size()const;

        ~string();
    };

    std::ostream& operator<<(std::ostream& os, const string& str) {
        os << str.m_ptr;
        return os;
    }

    string operator+(const string& lhs, const string& rhs) {
        std::size_t new_size = lhs.m_size + rhs.m_size;
        string result;
        
        result.m_cap = new_size + 1;
        result.m_size = new_size;
        result.m_ptr = new char[result.m_cap];

        std::memcpy(result.m_ptr, lhs.m_ptr, lhs.m_size);

        std::memcpy(result.m_ptr + lhs.m_size, rhs.m_ptr, rhs.m_size + 1); 

        return result;
    }
}

#include "string.tpp"