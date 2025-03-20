#include "string.hpp"

using namespace my;

void string::reallocate(std::size_t new_cap){
    char* new_ptr=new char[new_cap];
    for(std::size_t i=0; i<m_size; i++){
        new_ptr[i]=m_ptr[i];
    }
    delete[] m_ptr;
    m_ptr=new_ptr;
    m_cap=new_cap;
}

string::string()=default;

string::string(const char* init):string(){
    while(init!=nullptr){
        push_back(*init++);
    }
}

string::string(const string& other)=default;

string::string(string&& other)noexcept:m_ptr(std::move(other.m_ptr)), m_size(std::move(other.m_size)), m_cap(std::move(other.m_cap)){
    other.m_ptr=nullptr;
    other.m_size=0;
    other.m_cap=0;
}

string& string::operator=(const string& other){
    if(this!=&other){
        delete[] m_ptr;
        m_ptr=other.m_ptr;
        m_size=other.m_size;    
        m_cap=other.m_cap;
    }
    return *this;
}

string& string::operator=(string&& other)noexcept{
    if(this!=&other){
        delete[] m_ptr;
        m_ptr=other.m_ptr;
        m_size=other.m_size;
        m_cap=other.m_cap;
        other.m_ptr=nullptr;
        other.m_size=0;
        other.m_cap=0;
    }
    return *this;
}

void string::push_back(char c){
    if(m_size==m_cap){
        reallocate(m_cap==0?1:m_cap*2);
    }
    m_ptr[m_size++]=c;
}