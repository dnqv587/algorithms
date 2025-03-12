#pragma once
#include <array>
#include <functional>
#include <optional>

template <typename T,std::size_t M,std::size_t N>
std::optional<std::array<int,2>> DFSSearch(const std::array<std::array<T,N>,M>& array,const T& val) {
  bool visited[M][N]{false};
  std::function<std::optional<std::array<int,2>> (int,int)> DFS = [&DFS,&visited,&array,&val](const int m,const int n)->std::optional<std::array<int,2>> {
    if (m < 0 || m >=M || n < 0 || n >= N) {
      return std::nullopt;
    }
    if (array[m][n] == val) {
      return {{m,n}};
    }
    visited[m][n] = true;
    if (!visited[m-1][n]) {
      auto top = DFS(m-1,n);
      if (top.has_value()) {
        return top;
      }
    }
    if (!visited[m+1][n]) {
      auto bot = DFS(m+1,n);
      if (bot.has_value()) {
        return bot;
      }
    }
    if (!visited[m][n-1]) {
      auto left = DFS(m,n-1);
      if (left.has_value()) {
        return left;
      }
    }
    if (!visited[m][n+1]) {
      auto right = DFS(m,n+1);
      if (right.has_value()) {
        return right;
      }
    }
  };

  return DFS(0,0);;
}


