#include <iostream>
#include "stack.hpp"
#include <chrono>

int main(){
    my::stack<int> st1={5, 7, 9};
    std::cout<<"Testing push_back method for my::stack: adding 10\n";
    st1.push_back(10);
    if(st1.top()==10){
        std::cout<<"The last element is 10\n";
    }
    else{
        std::cout<<"The last element isn't 10\n";
    }
    my::stack<int> st2(st1);
    std::cout<<"Top of st2 is: "<<st2.top()<<std::endl;
    try{
        std::cout<<"Printing the elements of st1: \n";
        std::cout<<st1.top()<<std::endl;
        std::cout<<st1.top()<<std::endl;
        std::cout<<st1.top()<<std::endl;
        std::cout<<st1.top()<<std::endl;
    }
    catch(std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    my::stack<int> st3(std::move(st2));
    
    try{
        std::cout<<"Printing the elements of st2 after std::move(): \n";
        std::cout<<st2.top()<<std::endl;
    }
    catch(std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    try{
        std::cout<<"Printing the elements of st3: \n";
        std::cout<<st3.top()<<std::endl;
        std::cout<<st3.top()<<std::endl;
        std::cout<<st3.top()<<std::endl;
        std::cout<<st3.top()<<std::endl;
    }
    catch(std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    return 0;
}