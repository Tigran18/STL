#include <iostream>
#include "double_linked_list.h"

int main(){
    my::double_linked_list<int> integer_list{7, 8, 9, 10};
    for(std::size_t i=0; i<4; i++){
        std::cout<<integer_list[i]<<std::endl;
    }
    return 0;
}