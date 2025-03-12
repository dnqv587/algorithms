#pragma once
#include <array>

/// 二分查找
/// @tparam T
/// @tparam N
/// @param array 数组
/// @param val 值
/// @return 查找到则返回下标，否则返回-1
template <typename T,std::size_t N>
constexpr typename std::array<T,N>::size_type MiddleSearch(const std::array<T,N>& array,const T& val) {
  if constexpr (N == 0) {
    return -1;
  }
  using size_t = typename std::array<T,N>::size_type;
  size_t left = 0;
  size_t right = N-1;
  while (left <= right) {
    size_t mid = (left + right)/2;
    if (array[mid] > val) {
       right = mid -1;
    }
    else if (array[mid]<val) {
      left = mid+1;
    }
    else {
      return mid;;
    }
  }
  return -1;
}