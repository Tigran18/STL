#include <iostream>
#include "deque.hpp"

int main(){
    my::deque<int> deq1{4, 7, 8, 9};
    my::deque<int> deq2(std::move(deq1));
    std::cout<<deq1.size()<<std::endl;
    try{
        std::cout<<deq1.front()<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    deq2.pop_front();
    std::cout<<deq2.size()<<std::endl;
    std::cout<<deq2.front()<<std::endl;

    return 0;
}