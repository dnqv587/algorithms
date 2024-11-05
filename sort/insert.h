#pragma once
#include <algorithm>
#include <array>

//***********************************************
// name      : 插入排序
// brief     : 时间复杂度：O(n^2)，空间复杂度：O(1)
// attention : None
//***********************************************

template<class Iter,class CMP>
void insertSort(Iter begin,Iter end,CMP cmp)
{
	for(auto i = begin;i!=end;++i)
	{
        auto temp = *i;
		for(auto j=i-1;j>=begin;--j)
		{
			if(cmp(j,&temp))
			{
                *(j+1) = *j;
                *j=temp;
			}
		}
	}
}

template <typename T,size_t N,class CMP>
void insertSort(std::array<T,N>& arr,CMP cmp)
{
	for(int i=0;i<N;++i)
	{
		auto temp = arr[i];
		for(int j=i;j>=0;--j)
		{
			if(cmp(arr[j],temp))
			{
				arr[j+1] = arr[j];
				arr[j] = temp;
			}
		}
	}
}