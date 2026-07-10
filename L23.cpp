#include <iostream>
#include <queue>

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

struct cmp
{
  bool operator()(pair<int, pair<int, ListNode *>> &a, pair<int, pair<int, ListNode *>> &b)
  {
    // min heap
    if (a.first > b.first)
    {
      return true;
    }
    else
    {
      return false;
    }
  }
};

class Solution
{
public:
  ListNode *mergeKLists(vector<ListNode *> &lists)
  {
    // there are k sorted lists..
    ListNode *res = NULL;
    int numOfLists = lists.size();
    // heap will store as :- val , listNumber, pointer(to the same node)...
    priority_queue<pair<int, pair<int, ListNode *>>, vector<pair<int, pair<int, ListNode *>>>, cmp> heap;
    for (int i = 0; i < numOfLists; i++)
    {
      if (lists[i] != NULL)
      {
        int val = lists[i]->val;
        int listNum = i;
        ListNode *ptr = lists[i];
        pair<int, ListNode *> p1 = {i, ptr};
        pair<int, pair<int, ListNode *>> p2 = {val, p1};
        heap.push(p2);
      }
    }

    while (!heap.empty())
    {
      int val = heap.top().first;
      int listNum = heap.top().second.first;
      ListNode *ptr = heap.top().second.second;
      ListNode *newNode = new ListNode(val, res);
      res = newNode;
      heap.pop();
      ptr = ptr->next;

      if (ptr != NULL)
      {
        val = ptr->val;
        pair<int, ListNode *> p1 = {listNum, ptr};
        pair<int, pair<int, ListNode *>> p2 = {val, p1};
        heap.push(p2);
      }
    }

    // now reverse the particular linked list to find the correct answer...
    ListNode *prev = NULL;
    ListNode *curr = res;
    while (curr != NULL)
    {
      ListNode *nex = curr->next;
      curr->next = prev;

      prev = curr;
      curr = nex;
    }

    return prev;
  }
};

int main()
{
  Solution s1;
  ListNode *l1 = new ListNode(5);
  ListNode *l2 = new ListNode(4, l1);
  ListNode *l3 = new ListNode(1, l2);

  ListNode *l4 = new ListNode(4);
  ListNode *l5 = new ListNode(3, l4);
  ListNode *l6 = new ListNode(1, l5);

  ListNode *l7 = new ListNode(6);
  ListNode *l8 = new ListNode(2, l7);

  vector<ListNode *> lists = {{}};
  ListNode *res = s1.mergeKLists(lists);
  ListNode *currNode = res;
  while (currNode != NULL)
  {
    cout << currNode->val << " , ";
    currNode = currNode->next;
  }
}