#include <iostream>
#include "set.hpp"

int main(){
    my::set<int> s1={7, 8, 10, 9, 7, 2, 0, 9, -1};
    my::set<int> s2;
    s2=std::move(s1);
    std::cout<<"Printing s2 elements: ";
    for(auto& el : s2){
        std::cout<<el<<"  ";
    }
    std::cout<<std::endl;
    std::cout<<"Printing s1 elements after move assignement: ";
    for(auto& el : s1){
        std::cout<<el<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}