#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode
{
  int val;
  ListNode *next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
  ListNode *deleteDuplicates(ListNode *head)
  {
    if (head == nullptr)
    {
      return head;
    }
    ListNode *i = head;
    ListNode *j = head->next;

    ListNode *k = head;
    while (j != nullptr)
    {
      if ((j->val) != (k->val))
      {
        i = i->next;
        i->val = j->val;
      }
      j = j->next;
      k = k->next;
    }

    i->next = nullptr;
    return head;
  }
};

int main()
{
  ListNode *head;
  ListNode l1(1);
  head = &l1;
  ListNode l2(1);
  l1.next = &l2;
  ListNode l3(2);
  l2.next = &l3;

  Solution s1;
  s1.deleteDuplicates(head);
  ListNode *currentNode = head;

  while (currentNode != nullptr)
  {
    cout << currentNode->val << endl;
    currentNode = currentNode->next;
  }
}
