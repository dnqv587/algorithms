#include <iostream>
#include <string>
#include <algorithm>

void reverseWord(std::string& str) {
  if (str.empty()) {
    return;
  }

  for (auto iter=str.begin();iter!=str.end();++iter) {
    auto left = std::find_if(iter,str.end(),[](const char c) {
      return c!=' ';
    });
    if (left == str.end()) {
      return;
    }
    auto right = std::find_if(left,str.end(),[](const char c) {
      return c==' ';
    });
    std::reverse(left,right);
    iter = right;
  }
}

int main() {
  std::string str{"   123 word 123abc   "};
  reverseWord(str);
  std::cout<<str<<std::endl;
  return 0;
}