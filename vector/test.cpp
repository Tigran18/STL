#include <iostream>
#include <chrono>
#include "vector.h"
#include <vector>

int main(){
    my::vector<int> integer_vec={7, 8, 9, 10};
    for(std::size_t i=0; i<integer_vec.size(); i++){
        std::cout<<integer_vec[i]<<std::endl;
    }
    std::cout<<integer_vec.capacity()<<std::endl;
    return 0;
}