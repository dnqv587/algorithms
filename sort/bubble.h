#pragma once
#include <algorithm>
#include <array>

template<class Iter,class CMP>
void bubbleSort(Iter begin,Iter end,CMP cmp)
{
    for(auto i=begin;i!=end;++i)
    {
        for(auto j=begin;j!=begin+std::distance(i,end)-1;++j)
        {
            if(cmp(j,j+1))
            {
                std::swap(*(j+1),*j);
            }
        }
    }
}

template <typename T,size_t N,class CMP>
void bubbleSort(std::array<T,N>& arr,CMP cmp)
{
    for(int i =0;i<N;++i)
    {
        for(int j=0;j<N-i;++j)
        {
            if(cmp(arr[j],arr[j+1]))
            {
                std::swap(arr[j],arr[j+1]);
            }
        }
    }
}