#include <iostream>
#include <vector>
#include "list.h"

int main(){
    my::single_list<int> integer_list{4, 7, 9, -2};
    std::cout<<"The elements of the integer_list are: "<<std::endl;
    for(auto it=integer_list.begin(); it!=integer_list.end(); ++it){
        std::cout<<*it<<"  ";
    }
    std::cout<<"\n";
    my::single_list<std::vector<double>> vec_double_list={{7, 4.1, 2.01}, {-1.04, 8.75, 9.15}, {7.85, 9.64, 4,45, -8.1456}, {1, 0.2}};
    std::cout<<"The elements of the vec_double_list are: "<<std::endl;
    for(auto it=vec_double_list.begin(); it!=vec_double_list.end(); ++it){
        for(auto& el : *it){
            std::cout<<el<<"  ";
        }
        std::cout<<"\n";
    }
    std::cout<<"\n";
    return 0;
}