#include <iostream>
#include "list.hpp"

int main(){
    my::list<int> l1={7, 8, 9, 10};
    std::cout<<"l1 list elements are: ";
    for(auto it=l1.begin(); it!=l1.end(); ++it){
        std::cout<<*it<<"  ";
    }
    my::list<int> l2;
    l2=std::move(l1);
    std::cout<<"\nl2 list elements are: ";
    for(auto& el : l2){
        std::cout<<el<<"  ";
    }
    std::cout<<"\nl1 list elements after move are: ";
    for(auto it=l1.begin(); it!=l1.end(); ++it){
        std::cout<<*it<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}