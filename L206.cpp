#include <iostream>
using namespace std;

struct Node
{
  int data;
  Node *next;
  Node(int d)
  {
    data = d;
    next = NULL;
  }
};

class linkedList
{
  Node *head;

public:
  linkedList()
  {
    head = NULL;
  }
  void insert(int val)
  {
    Node *newNode = new Node(val); // a new node with a particular body....
    newNode->next = head;
    head = newNode; // appending the new node at the first place
    cout << "new node successfully added" << endl;
  }

  void display()
  {
    Node *currentNode;
    currentNode = head;
    while (currentNode != NULL)
    {
      cout << currentNode->data << " -> ";
      currentNode = currentNode->next;
    }
  }

  void reverse()
  {
    // in this we have to reverse a linked list...
    Node *prev;
    Node *curr;
    Node *nex;
    prev = NULL;
    curr = head;
    nex = curr->next;

    // now reverse in this part as...
    while (curr != NULL)
    {
      nex = curr->next;
      curr->next = prev;
      prev = curr;
      curr = nex;
    }

    head = prev;
  }
};

int main()
{
  linkedList l1;
  l1.insert(2);
  l1.insert(3);
  l1.insert(4);
  l1.insert(5);
  // l1.display();
  l1.reverse();
  l1.display();
}