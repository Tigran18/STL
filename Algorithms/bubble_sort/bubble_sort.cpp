#include <iostream>
#include <vector>

void bubble_sort(std::vector<int>& array){
    bool swapped=true;
    for(int i=0; i<array.size()-1; i++){
        for(int j=0; j<array.size(); j++){
            if(array[j]>array[j+1]){
                std::swap(array[j], array[j+1]);
                swapped=true;
            }
        }
        if(!swapped) return;
        else swapped=false;
    }
}

int main(){
    srand(time(0));
    std::vector<int> vec1;
    for(std::size_t i=0; i<20; i++){
        vec1.push_back(rand()%51-25);
    }
    bubble_sort(vec1);
    for(auto& el : vec1){
        std::cout<<el<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}