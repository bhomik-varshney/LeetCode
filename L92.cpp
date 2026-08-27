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
  ListNode *reverseBetween(ListNode *head, int left, int right)
  {
    // find the address of left , and address of right.
    if (left < right)
    {

      int counter = 1;
      ListNode *prev = NULL;
      ListNode *curr = head;
      ListNode *prevNode = NULL;
      bool reverse = false;
      ListNode *ptr1 = NULL;
      ListNode *ptr2 = NULL;
      ListNode *ptr3 = NULL;

      while (curr != NULL)
      {

        if (!reverse)
        {
          // check the pointer, are we in left or not..
          if (counter == left)
          {
            ptr1 = prevNode;
            ptr2 = curr;
            // we can do it now...
            ListNode *nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
            reverse = true;
          }
          else
          {
            prevNode = curr;
            curr = curr->next;
          }
        }
        else
        {
          // we need tp reverse it...
          if (counter == right)
          {
            ptr3 = curr->next;
            reverse = false;
            ListNode *nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
          }
          else
          {
            // simply reverse it...
            ListNode *nex = curr->next;
            curr->next = prev;
            prev = curr;
            curr = nex;
          }
        }

        counter++;
      }

      // final changes..
      if (ptr1 != NULL)
      {
        ptr1->next = prev;
      }
      if (ptr2 != NULL)
      {
        ptr2->next = ptr3;
      }

      if (left == 1)
      {
        return prev;
      }
      return head;
    }
    else
    {
      return head;
    }
  }
};