#include <iostream>
#include "forward_list.hpp"

int main(){
    my::forward_list<int> l1={7, 8, 9, 10};
    std::cout<<"elements of l1 are: ";
    for(auto it=l1.begin(); it!=l1.end(); ++it){
        std::cout<<*it<<"   ";
    }
    my::forward_list<int> l2;
    l2=std::move(l1);
    std::cout<<"\nelements of l2 are: ";
    for(auto it=l2.begin(); it!=l2.end(); ++it){
        std::cout<<*it<<"   ";
    }
    std::cout<<"\nelements of l1 after copy are: ";
    for(auto it=l1.begin(); it!=l1.end(); ++it){
        std::cout<<*it<<"   ";
    }
    std::cout<<"\nChecking iterators begin and end: ";
    for(auto& el : l2){
        std::cout<<el<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}