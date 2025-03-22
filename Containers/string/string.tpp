#include "string.hpp"
using namespace my;

void string::reallocate(std::size_t new_cap) {
    char* new_ptr = new char[new_cap + 1];
    std::memcpy(new_ptr, m_ptr, m_size);
    new_ptr[m_size] = '\0';
    delete[] m_ptr;
    m_ptr = new_ptr;
    m_cap = new_cap;
}

string::string() : m_ptr(new char[1]{'\0'}), m_size(0), m_cap(1) {}

string::string(const char* init){
    m_size = std::strlen(init);
    m_cap = m_size + 1;
    m_ptr = new char[m_cap];
    std::memcpy(m_ptr, init, m_size + 1);
}

string::string(const string& other) {
    m_size = other.m_size;
    m_cap = other.m_cap;
    m_ptr = new char[m_cap];
    std::memcpy(m_ptr, other.m_ptr, m_size + 1);
}

string::string(string&& other) noexcept : m_ptr(std::move(other.m_ptr)), m_size(other.m_size), m_cap(other.m_cap) {
    other.m_ptr = nullptr;
    other.m_size = 0;
    other.m_cap = 0;
}

string& string::operator=(const string& other) {
    if (this != &other) {
        delete[] m_ptr;
        m_size = other.m_size;
        m_cap = other.m_cap;
        m_ptr = new char[m_cap];
        std::memcpy(m_ptr, other.m_ptr, m_size + 1);
    }
    return *this;
}

string& string::operator=(string&& other) noexcept {
    if (this != &other) {
        // Free the existing resources
        delete[] m_ptr;

        // Steal the resources from 'other'
        m_ptr = other.m_ptr;
        m_size = other.m_size;
        m_cap = other.m_cap;

        // Leave 'other' in a valid but unspecified state
        other.m_ptr = nullptr;
        other.m_size = 0;
        other.m_cap = 0;
    }
    return *this;
}

void string::push_back(const char c){
    if(m_size==m_cap){
        reallocate(m_cap==0?1:2*m_cap);
    }
    m_ptr[m_size++]=c;
    m_ptr[m_size]='\0';
}

std::size_t string::size()const{
    return m_size;
}

string::~string() {
    delete[] m_ptr;
}