#include <gmock/gmock-matchers.h>

#include <iostream>

#include "gtest/gtest.h"
#include "search/DFS.h"

using namespace testing;

bool DFS(std::vector<std::vector<char> >& matrix,const std::string& word,int const index,std::vector<std::vector<bool>>& visited,int m, int n){
  if(m < 0|| m >=matrix.size()||n<0||n>=matrix.at(0).size()){
    return false;
  }
  if (visited[m][n]) {
    return false;
  }
  if(word.at(index) != matrix[m][n]){
    return false;
  }
  if (index==word.size()-1) {
    return true;
  }


  visited[m][n] = true;

  bool res = false;
  res |= DFS(matrix, word, index+1, visited, m - 1, n);
  res |= DFS(matrix, word, index+1, visited, m + 1, n);
  res |= DFS(matrix, word, index+1, visited, m, n - 1);
  res |= DFS(matrix, word, index+1, visited, m, n + 1);
  visited[m][n] = false;
  return res;
}

bool hasPath(std::vector<std::vector<char> >& matrix, std::string word) {
  // write code here
  const auto row = matrix.size();
  const auto column = matrix.at(0).size();
  std::vector<std::vector<bool>> visited{row,std::vector<bool>(column,false)};

  for(int m=0;m<row;++m){
    for(int n=0;n<column;++n){
      if(DFS(matrix,word,0,visited,m,n)){
        return true;
      }
    }
  }
  return false;
}

TEST(DFSSearchTest,DFSSearch) {
  constexpr std::array<std::array<int,3>,3> arr{{{1,2,3},
                                                  {4,5,6},
                                                    {7,8,9}}};
  EXPECT_THAT(DFSSearch(arr,6).value(),ElementsAre(1,2));
  EXPECT_THAT(DFSSearch(arr,9).value(),ElementsAre(2,2));
  EXPECT_THAT(DFSSearch(arr,5).value(),ElementsAre(1,1));
  EXPECT_THAT(DFSSearch(arr,4).value(),ElementsAre(1,0));

  constexpr std::array<std::array<int,10>,10> arr2{{
    {0,1,2,3,4,5,6,7,8,9},
    {10,11,12,13,14,15,16,17,18,19},
    {20,21,22,23,24,25,26,27,28,29},
    {30,31,32,33,34,35,36,37,38,39},
    {40,41,42,43,44,45,46,47,48,49},
    {50,51,52,53,54,55,56,57,58,59},
    {60,61,62,63,64,65,66,67,68,69},
    {70,71,72,73,74,75,76,77,78,79},
    {80,81,82,83,84,85,86,87,88,89},
    {90,91,92,93,94,95,96,97,98,99},
      }};
  EXPECT_THAT(DFSSearch(arr2,99).value(),ElementsAre(9,9));
  EXPECT_THAT(DFSSearch(arr2,55).value(),ElementsAre(5,5));
  EXPECT_THAT(DFSSearch(arr2,12).value(),ElementsAre(1,2));
  EXPECT_THAT(DFSSearch(arr2,0).value(),ElementsAre(0,0));
  EXPECT_THAT(DFSSearch(arr2,9).value(),ElementsAre(0,9));
  EXPECT_THAT(DFSSearch(arr2,80).value(),ElementsAre(8,0));

  constexpr std::array<std::array<int,3>,2> arr3{{{1,100,4433},
                                                {4625464,99,-100122752}}};
  EXPECT_THAT(DFSSearch(arr3,4625464).value(),ElementsAre(1,0));
  EXPECT_THAT(DFSSearch(arr3,-100122752).value(),ElementsAre(1,2));

  //TODO：会报异常
  //EXPECT_FALSE(DFSSearch(arr3,777).has_value());

  std::vector<std::vector<char> > matrix{{'a','b','c'},
                                          {'d','e','f'},
                                              {'a','c','d'}};
   std::vector<std::vector<char> > matrix2{{'A','B','C','E','H','J','I','G'},
                                            {'S','F','C','S','L','O','P','Q'},
                                            {'A','D','E','E','M','N','O','E'},
                                            {'A','D','I','D','E','J','F','M'},
                                            {'V','C','E','I','F','G','G','S'}};

  //std::cout<<"hasPath:"<<std::boolalpha<<hasPath(matrix2,"SLHECCEIDEJFGGFIE")<<std::endl;

  std::vector<std::vector<char> > matrix3{{'A'}};

  std::cout<<"hasPath:"<<std::boolalpha<<hasPath(matrix3,"B")<<std::endl;

}