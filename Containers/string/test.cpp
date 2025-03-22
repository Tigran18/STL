#include "string.hpp"
#include <iostream>

int main(){
    my::string str1="Hello World!";
    std::cout<<str1.size()<<std::endl;

    my::string str2;
    str2=std::move(str1);
    std::cout<<str2.size()<<std::endl;
    //std::cout<<str1;   //avoid printing the moved object, UB

    std::cout<<str2<<std::endl;
    my::string str3=str2;
    std::cout<<str3<<std::endl;
    return 0;
}