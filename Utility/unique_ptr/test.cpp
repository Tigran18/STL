#include <iostream>
#include "unique_ptr.hpp"

int main(){
    my::unique_ptr<int> ptr1(new int(5));
    std::cout<<*ptr1<<std::endl;
    return 0;
}