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
    std::cout<<"Inserting key 5 value 145.12 in m2"<<std::endl;
    m2.insert(5, 145.12);
    for(auto it=m2.begin(); it!=m2.end(); ++it){
        std::cout<<"Key="<<it->first<<", Value="<<it->second<<std::endl;
    }
    std::cout<<"Clearing the data in m2: \n";
    m2.clear();
    std::cout<<"Inserting new values: \n";
    double k=1.5;
    for(std::size_t i=0; i<5; i++){
        m2.insert(i, k=k*k);
    }
    for(auto& pair : m2){
        std::cout<<"Key="<<pair.first<<", Value="<<pair.second<<std::endl;
    }
    std::cout<<"Erasing the 4th element: \n";
    m2.erase(2);
    for(auto& pair : m2){
        std::cout<<"Key="<<pair.first<<", Value="<<pair.second<<std::endl;
    }
    return 0;
}