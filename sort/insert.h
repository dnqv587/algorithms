#pragma once
#include <algorithm>

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