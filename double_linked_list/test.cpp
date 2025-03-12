#include <iostream>
#include <chrono>
#include "list.h"

int main(){
    std::cout<<"Creating integer list and testing. "<<std::endl;
    std::cout<<"Testing forward iterator: "<<std::endl;
    my::list<int> integer_list={7, 8, 9, 10};
    try{
        for(auto it=integer_list.begin(); it!=integer_list.end(); ++it){
            std::cout<<*it<<std::endl;
        }
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    std::cout<<"Testing reverse iterator: "<<std::endl;
    try{
        for(auto it=integer_list.rbegin(); it!=integer_list.rend(); ++it){
            std::cout<<*it<<std::endl;
        }
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    return 0;
}