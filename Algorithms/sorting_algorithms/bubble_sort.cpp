#include <iostream>
#include <vector>
#include <list>
#include <chrono>

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
    auto start1=std::chrono::high_resolution_clock::now();
    bubble_sort(vec1);
    for(auto& el : vec1){
        std::cout<<el<<"  ";
    }
    auto end1=std::chrono::high_resolution_clock::now();
    auto duration1=std::chrono::duration_cast<std::chrono::nanoseconds>(end1-start1).count();
    std::cout<<"\nTime to sort "<<typeid(vec1).name()<<" of size "<<vec1.size()<<" is "<<duration1<<" nanoseconds"<<std::endl;
    std::cout<<std::endl;
    return 0;
}