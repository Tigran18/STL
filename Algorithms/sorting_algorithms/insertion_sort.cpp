#include <iostream>
#include <vector>

template <typename T>
void insertion_sort(T& array){
    for(int i=1; i<array.size(); i++){
        int key=array[i];
        int j=i-1;
        while(j>=0 && array[j]>key){
            array[j+1]=array[j];
            j--;
        }
        array[j+1]=key;
    }
}

int main(){
    srand(static_cast<unsigned>(time(0)));
    std::vector<int> vec1;
    int n;
    int max, min;
    std::cout<<"Enter the size of the vector: ";
    std::cin>>n;
    while(n<=0){
        std::cout<<"Incorrect size, enter more than 0: ";
        std::cin>>n;
    }
    std::cout<<"Enter the maximum and minimum values of the elements: ";
    std::cin>>max>>min;
    if (min >= max) {
        std::cout << "Error: Minimum value must be less than the maximum value.\n";
        return 1;
    }
    for (std::size_t i = 0; i < n; i++) {
        vec1.push_back(min + rand() % (max - min + 1)); 
    }
    std::cout<<"The original vector is: \n";
    for(auto& el : vec1){
        std::cout<<el<<"  ";
    }
    std::cout<<std::endl;
    insertion_sort(vec1);
    std::cout<<"The sorted vector is: \n";
    for(auto& el : vec1){
        std::cout<<el<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}