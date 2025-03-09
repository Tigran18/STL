#include <iostream>
#include <vector>
#include <chrono>
#include "single_linked_list.h"

int main(){
    my::single_linked_list<float> float_list={4.5f};
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
    my::single_linked_list<std::vector<double>> copy_vec(vec_double_list);
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
    auto start_for_0=std::chrono::high_resolution_clock::now();
    try{
        std::cout<<"new_integer_list element at index 0 is: "<<new_integer_list[0]<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    auto end_for_0=std::chrono::high_resolution_clock::now();
    auto duration_for_0=std::chrono::duration_cast<std::chrono::nanoseconds>(end_for_0-start_for_0).count();
    std::cout<<"Duration for 0 index is: "<<duration_for_0<<std::endl;
    auto start_for_2=std::chrono::high_resolution_clock::now();
    try{
        std::cout<<"new_integer_list element at index 2 is: "<<new_integer_list[2]<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }
    auto end_for_2=std::chrono::high_resolution_clock::now();
    auto duration_for_2=std::chrono::duration_cast<std::chrono::nanoseconds>(end_for_2-start_for_2).count();
    std::cout<<"Duration for 2 index is: "<<duration_for_2<<std::endl;
    try{
        std::cout<<"new_integer_list element at index less than 0: "<<new_integer_list[-1]<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }

    try{
        std::cout<<"new_integer_list element at index more than size: "<<new_integer_list[5]<<std::endl;
    }
    catch(const std::exception& ex){
        std::cout<<ex.what()<<std::endl;
    }

    std::cout<<"new_integer_list after inserting 5 at index 2 is: "<<std::endl;
    new_integer_list.insert_at(new_integer_list.begin()+2, 5);
    for(auto it=new_integer_list.begin(); it!=new_integer_list.end(); ++it){
        std::cout<<*it<<"  ";
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

//comments added for check
