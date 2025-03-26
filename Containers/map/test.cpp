#include <iostream>
#include "map.hpp"

int main(){
    my::map<int, double> m1={{4, 7.02}, {1, 7.84}};
    for(std::size_t i=0; i<m1.size(); i++){
        std::cout<<m1[i]<<"  ";
    }
    std::cout<<"Number of elements: "<<m1.size()<<std::endl;
    return 0;
}