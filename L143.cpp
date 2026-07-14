#include <iostream>
using namespace std;

//  Definition for singly-linked list.
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
  void reorderList(ListNode *head)
  {
    // reverse the linked list..
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
      slow = slow->next;
      fast = fast->next->next;
    }

    // middle has been found, now just reverse the linked List....
    ListNode *prev = NULL;
    ListNode *curr = slow;
    while (curr != NULL)
    {
      ListNode *nex = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nex;
    }

    ListNode *j = prev;
    ListNode *i = head;
    cout << i->val << endl;
    cout << j->val << endl;
    // make the new linked list as :-
    while (i != NULL && j != NULL)
    {
      ListNode *nex1 = i->next;
      ListNode *nex2 = j->next;
      i->next = j;
      j->next = nex1;
      j = nex2;
      i = nex1;
    }
    if (i != NULL && i->next != NULL)
    {
      i->next = NULL;
    }

    return;
  }
};