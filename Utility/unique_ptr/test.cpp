#include <iostream>
#include "unique_ptr.hpp"
#include <utility>
#include <memory>

int main(){
    my::unique_ptr<int> ptr1(new int[4]{4, 6, 8, 10});
    std::cout<<*(ptr1+1)<<std::endl;
    return 0;
}