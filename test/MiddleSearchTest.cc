#include "search/MiddleSearch.h"
#include "gtest/gtest.h"

using namespace testing;

TEST(MiddleSearchTest,MiddleSearch)
{

  constexpr std::array arr{1,2,3,4,5,6,7};
  EXPECT_EQ(MiddleSearch(arr,5),4);
  EXPECT_EQ(MiddleSearch(arr,8),-1);
  EXPECT_EQ(MiddleSearch(arr,1),0);
  EXPECT_EQ(MiddleSearch(arr,7),6);
  EXPECT_EQ(MiddleSearch(arr,4),3);
  constexpr std::array<int,0> arr1{};
  EXPECT_EQ(MiddleSearch(arr1,1),-1);
  constexpr std::array arr2{1,2};
  EXPECT_EQ(MiddleSearch(arr2,1),0);
  EXPECT_EQ(MiddleSearch(arr2,2),1);
}