#include "sort/select.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <array>

TEST(SortTest,select)
{
	std::array<int,10> arr{19,88,72,6,556,4,3,25666,12,0};

	SelectSort(arr.begin(),arr.end(),[](auto l,auto r){
	  return *l > *r;
	});
	using namespace testing;
	EXPECT_THAT(arr, WhenSorted(ElementsAre(0, 3, 4, 6, 12, 19, 72, 88, 556, 25666)));
}
