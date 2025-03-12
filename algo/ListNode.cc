#include <iostream>
#include <unordered_set>

struct ListNode {
  int val;
  struct ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
};

ListNode* addInList(ListNode* head1, ListNode* head2) {
  // write code here
  ListNode* curNode1 = head1;
  ListNode* curNode2 = head2;
  int val1 = 0;
  int val2 = 0;
  while (curNode1 || curNode2) {
    if (curNode1) {
      val1 = val1 * 10 + curNode1->val;
      curNode1 = curNode1->next;
    }
    if (curNode2) {
      val2 = val2 * 10 + curNode2->val;
      curNode2 = curNode2->next;
    }
  }
  int addVal = val1 + val2;
  int entry = 1;
  int temp = addVal/10;
  while (temp) {
    entry *=10;
    temp /=10;
  }
  ListNode* newNode = new ListNode(addVal/entry);
  ListNode* curNode = newNode;
  addVal %= entry;
  entry /=10;
  while (addVal) {
    newNode->next = new ListNode(addVal/entry);
    newNode=newNode->next;
    addVal %= entry;
    entry /=10;
  }
  return curNode;
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

  std::cout<<addInList(head1,head2)->val<<std::endl;

}