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

    
}

#include "string.tpp"