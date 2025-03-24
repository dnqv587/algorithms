#include <iostream>
#include <unordered_set>
#include <queue>
#include <stack>
#include <algorithm>
#include <array>

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

struct TreeNode {
  int val;
  struct TreeNode* left;
  struct TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};


template<typename T,std::size_t N>
void sort(std::array<T,N>& arr) {
  for (int i=0;i<N;++i) {
    int min = i;
    for (int j=i;j<N;++j) {
      if (arr[j]<arr[min]) {
        min = j;
      }
    }
    std::swap(arr[i],arr[min]);
  }
}

int main()
{
  ListNode* head1 = new ListNode(1);
  head1->next = new ListNode(2);
  head1->next->next = new ListNode(3);
  head1->next->next->next = new ListNode(7);
  head1->next->next->next->next = new ListNode(8);

  ListNode* head2 = new ListNode(4);
  head2->next = new ListNode(5);
  head2->next->next = new ListNode(6);

  TreeNode* tree = new TreeNode(1);
  tree->left =  new TreeNode(2);
  tree->right =  new TreeNode(3);
  tree->left->left =  new TreeNode(4);
  tree->left->right =  new TreeNode(5);

  tree->right->right =  new TreeNode(6);

  std::array<int,10> arr{19,88,72,6,556,4,3,25666,12,0};
  sort(arr);
  for (auto i:arr) {
    std::cout<<i<<",";
  }
  std::cout<<std::endl;
}