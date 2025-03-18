#include <iostream>
#include "stack.hpp"
#include <chrono>

int main(){
    my::stack<int> st1={5, 7, 9};
    st1.push_back(10);
    std::cout<<st1.top()<<std::endl;
    std::cout<<st1.top()<<std::endl;
    std::cout<<st1.top()<<std::endl;
    std::cout<<st1.top()<<std::endl;
    
    std::cout<<st1.top()<<std::endl;
    return 0;
}