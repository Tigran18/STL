#include <iostream>
#include "map.hpp"
#include <vector>

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
    std::cout<<"Creating and printing m2 for a range of pairs: \n";
    std::vector<std::pair<int, double>> pairs{{7, 8.15}, {8, 1.154}, {1, 0.125}, {-1, 48.75}, {11, 14.49}};
    my::map<int, double> m2(pairs.begin(), pairs.end());
    for(auto it=m2.rbegin(); it!=m2.rend(); ++it){
        std::cout<<"Key="<<it->first<<", Value="<<it->second<<std::endl;
    }
    return 0;
}