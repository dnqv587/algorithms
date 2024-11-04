#pragma once
#include <array>
#include <functional>

template <typename T,size_t N,class FUNC>
void SelectSort(std::array<T,N>& arr,FUNC cmp)
{
	for(int i=0;i<N;++i)
	{
		int minPos = i;
		for(int j=i;j<N;++j)
		{
			if(cmp(arr[minPos],arr[j]))
			{
				minPos = j;
			}
		}
		std::swap(arr[i],arr[minPos]);
	}
}

template <typename Iter,class CMP>
void SelectSort(Iter begin,Iter end,CMP cmp)
{
	for(auto i=begin;i!=end;++i)
	{
		auto min = i;
		for(auto j=i;j!=end;++j)
		{
			if(cmp(min,j))
			{
				min = j;
			}
		}
		std::swap(*i,*min);
	}
}