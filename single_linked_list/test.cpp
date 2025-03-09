#include <iostream>
#include <vector>
#include "single_linked_list.h"

int main(){
    my::single_linked_list<int> integer_list{4, 7, 9, -2};
    integer_list.delete_at(0);
    std::cout<<"The elements of the integer_list are: "<<std::endl;
    for(auto it=integer_list.begin(); it!=integer_list.end(); ++it){
        std::cout<<*it<<"  ";
    }
    std::cout<<"\n";
    my::single_linked_list<std::vector<double>> vec_double_list={{7, 4.1, 2.01}, {-1.04, 8.75, 9.15}, {7.85, 9.64, 4, 45, -8.1456}, {1, 0.2}};
    std::cout<<"The elements of the vec_double_list are: "<<std::endl;
    for(auto it=vec_double_list.begin(); it!=vec_double_list.end(); ++it){
        for(auto& el : *it){
            std::cout<<el<<"  ";
        }
        std::cout<<"\n";
    }
    my::single_linked_list<std::vector<double>> copy_vec=vec_double_list;
    std::cout<<"\nChecking the work of copy constructor: \n";
    std::cout<<"The elements of the vec_double_list are: "<<std::endl;
    for(auto it=copy_vec.begin(); it!=copy_vec.end(); ++it){
        for(auto& el : *it){
            std::cout<<el<<"  ";
        }
        std::cout<<"\n";
    }
    
    std::cout<<"\nChecking the work of move constructor: ";
    my::single_linked_list<int> new_integer_list=std::move(integer_list);
    std::cout<<"The elements of the new_integer_list are: "<<std::endl;
    for(auto it=new_integer_list.begin(); it!=new_integer_list.end(); ++it){
        std::cout<<*it<<"  ";
    }
    std::cout<<std::endl;
    std::cout<<"The elements of the integer_list are: "<<std::endl;
    for(auto it=integer_list.begin(); it!=integer_list.end(); ++it){
        std::cout<<*it<<"  ";
    }
    try{
        std::cout<<new_integer_list[1]<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }

    try{
        std::cout<<new_integer_list[-1]<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }

    try{
        std::cout<<new_integer_list[5]<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }

    std::cout<<std::endl;
    std::cout<<"new_integer_list after «clear» method: "<<std::endl;
    new_integer_list.clear();
    for(auto it=new_integer_list.begin(); it!=new_integer_list.end(); ++it){
        std::cout<<*it<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}