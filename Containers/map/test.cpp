#include <iostream>
#include "map.hpp"

int main(){
    my::map<int, double> m1={{4, 7.02}, {1, 7.84}};
    std::cout<<"Elements of m1: ";
    for(auto& pair: m1){
        std::cout<<pair.first<<"  "<<pair.second<<", ";
    }
    std::cout<<"Number of elements: "<<m1.size()<<std::endl;
    try{
        std::cout<<"Element at index 2: "<<m1.at(2)<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    return 0;
}