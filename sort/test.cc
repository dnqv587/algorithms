#include "select.h"
#include "insert.h"
#include "bubble.h"
#include <iostream>

void selectTest()
{
	std::array<int,10> arr{19,88,72,6,556,4,3,25666,12,0};

	SelectSort(arr.begin(),arr.end(),[](auto l,auto r){
		return *l > *r;
	});


	for(auto i: arr)
	{
		std::cout<<i<<std::endl;
	}
}

void insertTest()
{
    std::array<int,10> arr{19,88,72,6,556,4,3,25666,12,0};

	insertSort(arr.begin(),arr.end(),[](auto l,auto r){
	  return *l > *r;
	});


	for(auto i: arr)
	{
		std::cout<<i<<std::endl;
	}
}

void bubbleTest()
{
    std::array<int,10> arr{19,88,72,6,556,4,3,25666,12,0};
    std::array<int,10> arr1{19,88,72,6,556,4,3,25666,12,0};

    bubbleSort(arr.begin(),arr.end(),[](auto l,auto r){
        return *l > *r;
    });

    bubbleSort(arr1,[](const auto& lhs,const auto & rhs){
        return lhs > rhs;
    });


    for(auto i: arr)
    {
        std::cout<<i<<std::endl;
    }
    std::cout<<" ------- "<<std::endl;
    for(auto i: arr1)
    {
        std::cout<<i<<std::endl;
    }
}

int main()
{
	//selectTest();
	//insertTest();
    bubbleTest();

	return 0;
}