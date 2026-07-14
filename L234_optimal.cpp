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
  bool isPalindrome(ListNode *head)
  {
    // optimal approach...
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast != NULL)
    {
      if (slow->next != NULL)
      {
        slow = slow->next;
      }
      if (fast->next != NULL && fast->next->next != NULL)
      {
        fast = fast->next->next;
      }
      else
      {
        // if one of them is null, just make fast = null
        fast = NULL;
      }
    }
    // now at the slow pointer, we are the middle of the linked list, reverse the linked List...
    ListNode *prev = NULL;
    ListNode *curr = slow;
    while (curr != NULL)
    {
      ListNode *nex = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nex;
    }

    ListNode *i = prev;
    ListNode *j = head;

    while (i != NULL && j != NULL)
    {
      if (i->val == j->val)
      {
        i = i->next;
        j = j->next;
      }
      else
      {
        return false;
      }
    }
    return true;
  }
};