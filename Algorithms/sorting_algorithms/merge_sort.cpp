#include <iostream>
#include <vector>
#include <list>


template <typename T>
void merge(T& array, int left, int mid, int right) {
    std::vector<typename T::value_type> temp;
    int i = left, j = mid + 1;

    while (i <= mid && j <= right) {
        if (array[i] <= array[j])
            temp.push_back(array[i++]);
        else
            temp.push_back(array[j++]);
    }

    while (i <= mid) temp.push_back(array[i++]);
    while (j <= right) temp.push_back(array[j++]);

    for (int k = left; k <= right; k++) {
        array[k] = temp[k - left];
    }
}



template <typename T>
void merge_sort(T& array, int left, int right) {
    if (left >= right) return;
    int mid = left + (right - left) / 2;
    merge_sort(array, left, mid);
    merge_sort(array, mid + 1, right);
    merge(array, left, mid, right);
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
    merge_sort(vec1, 0, vec1.size());
    std::cout<<"The sorted vector is: \n";
    for(auto& el : vec1){
        std::cout<<el<<"  ";
    }
    std::cout<<std::endl;
    
    return 0;
}