#include <iostream>
#include <array>

template <typename T,size_t N>
void sort(std::array<T,N>& arr){
    for(int i=0;i<N-1;++i){
        for(int j=0;j<N-i-1;++j){
            if(arr[j]>arr[j+1]){
                T temp{std::move(arr[j])};
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    //return arr;
}

template <typename T,size_t N>
void sortDesc(std::array<T,N>& arr){
    for(int i=0;i<N-1;++i){
        for(int j=0;j<N-i-1;++j){
            if(arr[j]<arr[j+1]){
                T temp{std::move(arr[j])};
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    //return arr;
}

int main(){
    std::array<int,14> arr{10,9,8,7,6,5,4,3,2,1,15,22,33,44};
    sort(arr);
    for(const auto& i:arr){
        std::cout<<i<<',';
    }
    std::cout<<std::endl;

    std::array<int,14> arr1{10,9,8,7,6,5,4,3,2,1,15,22,33,44};
    sortDesc(arr1);
    for(const auto& i:arr1){
        std::cout<<i<<',';
    }
    std::cout<<std::endl;

    return 0;
}