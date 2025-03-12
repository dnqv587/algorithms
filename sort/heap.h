#pragma once
#include <array>
#include <algorithm>

/* 堆排序
 * 节点的关系：
 * 下标为i的节点的父节点下标：(i-1)/2 【整数除法】
 * 下标为i的节点的左孩子下标：i*2+1
 * 下标为i的节点的右孩子下标：i*2+2
 */

/// 维护堆的性质 -- 大顶堆
/// @param arr 数组
/// @param n 剩余数组的个数
/// @param i 待维护节点的下标
template <typename T>
void heapify(T arr[], const int n,int i) {
  int largest = i;
  int lson = 2*i+1;
  int rson = 2*i+2;
  if (lson<n && arr[largest]<arr[lson]) {
    largest = lson;
  }
  if (rson<n && arr[largest]<arr[rson]) {
    largest = rson;
  }
  if (largest != i) {
    std::swap(arr[largest],arr[i]);
    heapify(arr,n,largest);
  }
}

template <typename T,std::size_t N>
void HeapSort(std::array<T,N>& arr) {
  // 建堆
  for (int i = N / 2 - 1;i>=0;--i) {
    heapify(arr.data(),N,i);
  }
  //排序
  for (int i = N-1;i>0;--i) {
    std::swap(arr[i],arr[0]);
    heapify(arr.data(),i,0);
  }
}