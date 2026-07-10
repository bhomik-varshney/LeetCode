#include <iostream>
#include <vector>
using namespace std;

struct node
{
  int val;
  node *next;

  node(int v)
  {
    val = v;
    next = NULL;
  }
};

class Graph
{
public:
  vector<node *> adjacencyList;
  int vertices;
  Graph(int v)
  {
    vertices = v;
    adjacencyList.resize(vertices);

    for (int i = 0; i < adjacencyList.size(); i++)
    {
      adjacencyList[i] = NULL;
    }
  }

  void insert(int src, int des)
  {
    node *newNode = new node(des);

    if (adjacencyList[src] == NULL)
    {
      adjacencyList[src] = newNode;
    }
    else
    {
      node *temp = adjacencyList[src];
      newNode->next = temp;
      adjacencyList[src] = newNode;
    }
  }

  void display()
  {
    for (int i = 0; i < vertices; i++)
    {
      cout << i << " -> ";
      node *currNode = adjacencyList[i];
      while (currNode != NULL)
      {
        cout << currNode->val << ", ";
        currNode = currNode->next;
      }
      cout << endl;
    }
  }
};

int main()
{
  Graph g1(5);
  g1.insert(0, 2);
  g1.insert(1, 3);
  g1.insert(0, 1);
  g1.insert(3, 1);
  g1.insert(0, 4);
  g1.display();
}