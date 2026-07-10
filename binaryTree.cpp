#include <iostream>
using namespace std;

// make a data type using struct

struct node
{
  int data;
  node *left;
  node *right;

  node(int val)
  {
    data = val;
    left = NULL;
    right = NULL;
  }
};

class binaryTree
{

  node *insertNode(int val)
  {
    if (val == -1)
    {
      return NULL;
    }

    node *newNode = new node(val);
    int leftValue;
    int rightValue;

    cout << "enter the left child of : " << val << " : ";
    cin >> leftValue;
    newNode->left = insertNode(leftValue);
    cout << "enter the right child of : " << val << " : ";
    cin >> rightValue;
    newNode->right = insertNode(rightValue);

    return newNode;
  }

  void inorderHelper(node *n)
  {
    // it is in :- LNR
    if (n == NULL)
    {
      return;
    }
    else
    {
      node *currNode = n;
      inorderHelper(currNode->left);
      cout << n->data << " , ";
      inorderHelper(currNode->right);
    }
  }

  void LeafNodesHelper(node *n)
  {
    if (n != NULL)
    {
      if (n->left == NULL && n->right == NULL)
      {
        cout << n->data << " , ";
        return;
      }
      if (n->left != NULL)
      {
        LeafNodesHelper(n->left);
      }
      if (n->right != NULL)
      {
        LeafNodesHelper(n->right);
      }
    }
    else
    {
      return;
    }
  }

  int heightHelper(node *n, int h)
  {
    if (n == NULL)
    {
      return h;
    }
    else
    {
      if (n->left == NULL && n->right == NULL)
      {
        return (h + 1);
      }
      else if (n->left != NULL && n->right == NULL)
      {
        return heightHelper(n->left, h + 1);
      }
      else if (n->right != NULL && n->left == NULL)
      {
        return heightHelper(n->left, h + 1);
      }
      else
      {
        int leftHeight = heightHelper(n->left, h + 1);
        int rightHeight = heightHelper(n->right, h + 1);
        return max(leftHeight, rightHeight);
      }
    }
  }

  void searchHelper(node *n, int val, vector<node *> &res)
  {
    if (n != NULL)
    {
      if (n->data == val)
      {
        res.push_back(n);
      }

      // search in the left...
      searchHelper(n->left, val, res);
      searchHelper(n->right, val, res);
    }
    else
    {
      return;
    }
  }

public:
  node *root;

  void insert(int val)
  {
    root = insertNode(val);
  }

  void inorderTraversal()
  {
    inorderHelper(root);
    cout << endl;
  }

  void leafNodes()
  {
    LeafNodesHelper(root);
    cout << endl;
  }
  void height()
  {
    int h = 0;
    cout << "height of the tree is : " << heightHelper(root, h);
  }

  vector<node *> search(int val)
  {
    vector<node *> res;
    searchHelper(root, val, res);
    if (res.size() == 0)
    {
      cout << "no element in the tree found" << endl;
    }
    return res;
  }
};

int main()
{
  binaryTree t1;
  int val;
  cout << "enter the root value : ";
  cin >> val;
  t1.insert(val);
  t1.inorderTraversal();
  t1.leafNodes();
  t1.height();
  int choice = 1;
  while (choice != -1)
  {
    int val;
    cout << "write the value of element that you want to search : ";
    cin >> val;
    vector<node *> res = t1.search(val);
    for (auto i : res)
    {
      cout << i->data << endl;
    }
    cout << "enter the choice : ";
    cin >> choice;
  }
}