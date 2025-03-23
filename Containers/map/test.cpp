#include <iostream>
#include "map.hpp"

int main(){
    my::map<int, double> m1={{4, 7.02}, {1, 7.84}};
    std::cout<<m1.size()<<std::endl;
    return 0;
}