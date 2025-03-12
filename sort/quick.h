#pragma once
#include <array>

template <typename T,std::size_t N>
int partition(std::array<T,N>& arr,int begin,int end) {
  T pivot = arr[end];
  int left = begin;
  int right= end;
  while (left < right) {
    while (left < right && arr[left] <= pivot) {
      ++left;
    }
    if (left < right) {
      std::swap(arr[left],arr[right--]);
    }
    while (left < right && arr[right] > pivot) {
      --right;
    }
    if (left < right) {
      std::swap(arr[left++],arr[right]);
    }
  }
  return left;
}


template <typename T,std::size_t N>
void sort_recursive(std::array<T,N>& arr,int begin,int end) {
  if (begin >= end) {
    return;
  }
  const int mid = partition(arr,begin,end);
  sort_recursive(arr,begin,mid-1);
  sort_recursive(arr,mid+1,end);
}

template <typename T,std::size_t N>
void QuickSort(std::array<T,N>& arr) {
  sort_recursive(arr,0,N-1);
}