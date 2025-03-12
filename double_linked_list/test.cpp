#include <iostream>
#include <chrono>
#include "list.h"

int main(){
    std::cout<<"Creating integer list and testing. "<<std::endl;
    std::cout<<"Testing forward iterator: "<<std::endl;
    my::list<int> integer_list={7, 8, 9, 10};
    auto start_for_integer1=std::chrono::high_resolution_clock::now();
    try{
        for(auto it=integer_list.begin(); it!=integer_list.end(); ++it){
            std::cout<<*it<<std::endl;
        }
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    auto end_for_integer1=std::chrono::high_resolution_clock::now();
    auto duration_for_forward_iterator=std::chrono::duration_cast<std::chrono::nanoseconds>(end_for_integer1-start_for_integer1).count();
    std::cout<<"Duration for forward iterator: "<<duration_for_forward_iterator<<std::endl;
    std::cout<<"Testing reverse iterator: "<<std::endl;
    auto start_for_integer2=std::chrono::high_resolution_clock::now();
    try{
        for(auto it=integer_list.rbegin(); it!=integer_list.rend(); ++it){
            std::cout<<*it<<std::endl;
        }
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    auto end_for_integer2=std::chrono::high_resolution_clock::now();
    auto duration_for_reverse_iterator=std::chrono::duration_cast<std::chrono::nanoseconds>(end_for_integer2-start_for_integer2).count();
    std::cout<<"Duration for reverse iterator: "<<duration_for_reverse_iterator<<std::endl;
    try{
        std::cout<<integer_list[0]<<std::endl;
        std::cout<<integer_list[6]<<std::endl;
        std::cout<<integer_list[-5]<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    return 0;
}