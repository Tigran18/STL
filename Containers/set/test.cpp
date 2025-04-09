#include <iostream>
#include "set.hpp"

int main(){
    my::set<int> s1={7, 8, 10, 9, 7, 2, 0, 9, -1};
    my::set<int> s2={1, 8, 9, 6};
    s1.insert(5);
    s1.remove(5);
    s2=std::move(s1);
    for(auto& el : s1){
        std::cout<<el<<"  ";
    }
    std::cout<<std::endl;
    for(auto& el : s2){
        std::cout<<el<<"  ";
    }
    std::cout<<std::endl;
    auto it=s2.find(2);
    std::cout<<"returning 2: "<<*it<<std::endl;
    std::cout<<"Finding 9: ";
    if(s2.contains(9)){
        std::cout<<"Yes"<<std::endl;
    }
    else{
        std::cout<<"No"<<std::endl;
    }
    std::cout<<"Finding 5: ";
    if(s2.contains(5)){
        std::cout<<"Yes"<<std::endl;
    }
    else{
        std::cout<<"No"<<std::endl;
    }
    return 0;
}