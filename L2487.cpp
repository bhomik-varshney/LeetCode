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
  ListNode *reverseLinkedList(ListNode *head)
  {
    ListNode *prev = NULL;
    ListNode *curr = head;
    while (curr != NULL)
    {
      ListNode *nex = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nex;
    }

    return prev;
  }

  ListNode *removeNodes(ListNode *head)
  {
    ListNode *newHead = reverseLinkedList(head);

    stack<int> st;
    ListNode *currNode = newHead;
    ListNode *prevNode = NULL;
    st.push(currNode->val);

    while (currNode != NULL)
    {
      // i need to check it now..
      if (!st.empty())
      {
        int elem = st.top();
        if (elem <= currNode->val)
        {
          // we need to take that node...
          st.pop();
          st.push(currNode->val);
          if (prevNode != NULL)
          {
            prevNode->next = currNode;
          }

          prevNode = currNode;
        }
      }

      currNode = currNode->next;
    }

    prevNode->next = NULL;

    // again reverse the ll...

    return reverseLinkedList(newHead);
  }
};