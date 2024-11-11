#pragma once
#include <algorithm>

template <class Iter,class CMP>
void shellSort(Iter begin,Iter end,CMP cmp)
{
	int len = std::distance(begin,end);
	for(int step=len/3;step>0;step /=3)
	{
		for(int i=step;i<len;++i)
		{
			auto temp = *(begin+i);
			for(int j=i;j>step-1;j-=step)
			{
				if(cmp(begin+j,&temp))
				{
					*(begin+j+step) = *(begin+j);
					*(begin+j) = temp;
				}
			}
		}
	}
}