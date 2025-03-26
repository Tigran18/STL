#include <iostream>
#include "map.hpp"

int main(){
    my::map<int, double> m1={{4, 7.02}, {1, 7.84}};
    for(auto pair: m1){
        std::cout<<pair.first<<"-"<<pair.second<<endl;
    }
    return 0;
}