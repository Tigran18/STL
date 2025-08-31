#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

template <typename T>
void counting_sort(std::vector<T>& vec, size_t n, int max, int min) {
    std::vector<int> count(max - min + 1, 0);
    std::vector<T> output(n);
    for (size_t i = 0; i < n; ++i) {
        count[vec[i] - min]++;
    }
    for (size_t i = 1; i < count.size(); ++i) {
        count[i] += count[i - 1];
    }
    for (int i = static_cast<int>(n) - 1; i >= 0; --i) {
        output[count[vec[i] - min] - 1] = vec[i];
        count[vec[i] - min]--;
    }
    for (size_t i = 0; i < n; ++i) {
        vec[i] = output[i];
    }
}


int main(){
    srand(static_cast<unsigned>(time(0)));
    size_t n;
    int min, max;
    std::vector<int> vec;
    std::cout<<"Enter the size of the array: ";
    std::cin>>n;
    while(n<=0){
        std::cout<<"Enter valid size: ";
        std::cin>>n;
    }
    std::cout<<"Enter max and min numbers of the array: \n";
    std::cout<<"Max: ";
    std::cin>>max;
    std::cout<<"Min: ";
    std::cin>>min;
    while(max<=min){
        std::cout<<"Max can't be less than min, enter valid numbers: ";
        std::cout<<"Max: ";
        std::cin>>max;
        std::cout<<"Min: ";
        std::cin>>min;
    }
    for(size_t i=0; i<n; ++i){
        vec.push_back(rand()%(max-min+1)+min);
    }
    std::cout<<"Original vector: ";
    for(const auto& el : vec){
        std::cout<<el<<"  ";
    }
    counting_sort(vec, n, max, min);
    std::cout<<"\nVector after counting sort: ";
    for(const auto& el : vec){
        std::cout<<el<<"  ";
    }
    std::cout<<std::endl;
    return 0;
}