#include <iostream>
#include "deque.hpp"

int main(){
    my::deque<int> deq1{4, 7, 8, 9};
    std::cout<<"Moving deq1 to deq2: "<<std::endl;
    my::deque<int> deq2(std::move(deq1));
    std::cout<<"Checking the size of deq1: "<<deq1.size()<<std::endl;
    try{
        std::cout<<"printing the first element of deq1: ";
        std::cout<<deq1.front()<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    std::cout<<"Checking pop_front method for deq2: "<<std::endl;
    deq2.pop_front();
    std::cout<<"Checking the size of deq2 after pop_front method: "<<deq2.size()<<std::endl;
    std::cout<<"Printing the first element of deq2: "<<deq2.front()<<std::endl;
    try{
        std::cout<<"Changing the element at index 2 with method 'at': \n";
        deq2.at(2)=2;
        std::cout<<"Checking the work of method 'at' index 2: "<<deq2.at(2)<<std::endl;
        std::cout<<"Checking the work of method 'at' index -1: "<<deq2.at(-1)<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    try{
        std::cout<<"Changing the element at index 2 with operator[]: \n";
        deq2[2]=2;
        std::cout<<"Checking the work of method 'at' index 2: "<<deq2[2]<<std::endl;
        std::cout<<"Checking the work of method 'at' index -1: "<<deq2[-1]<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }

    return 0;
}