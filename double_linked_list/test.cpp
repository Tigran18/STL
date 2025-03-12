#include <iostream>
#include <chrono>
#include "list.h"

int main(){
    std::cout<<"Creating integer list and testing. "<<std::endl;
    my::list<int> integer_list={7, 8, 9, 10};
    for(auto it=integer_list.rbegin(); it!=integer_list.rend(); ++it){
        std::cout<<*it<<std::endl;
    }
    return 0;
}