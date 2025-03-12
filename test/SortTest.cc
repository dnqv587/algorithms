#include "sort/select.h"
#include "sort/quick.h"
#include "sort/heap.h"
#include "gtest/gtest.h"
#include "gmock/gmock.h"
#include <array>

TEST(SortTest,sort)
{
  std::array arr{19,88,72,6,556,4,3,25666,12,0,59844,48989,666,15554,1,123,88,88};

  //SelectSort(arr.begin(), arr.end(), [](auto l, auto r) { return *l > *r; });
  QuickSort(arr);
  for (auto i:arr) {
    std::cout<<i<<std::endl;
  }
  // using namespace testing;
  // EXPECT_THAT(arr, WhenSortedBy(std::less(), ElementsAre(0, 3, 4, 6, 12, 19, 72,88, 556, 25666)));
}
