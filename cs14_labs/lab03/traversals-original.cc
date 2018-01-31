#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <stack>
#include "helper.hh"

using namespace std;

template <typename T>
vector<T> preorderTraversalNoRecursion(Node<T>* root) 
{
    stack<Node<T>*> s;
    vector<T> output;
    if (!root)
        return output;
    s.push(root);
    while (!s.empty())
    {
        Node<T>* tmpPtr = s.top();
        output.push_back(tmpPtr->value);
        s.pop();
        //Go right before going left
        if (tmpPtr->right)
            s.push(tmpPtr->right);
        if (tmpPtr->left)
            s.push(tmpPtr->left);
    }
    return output;
}

template <typename T>
vector<T> inorderTraversalNoRecursion(Node<T>* root) 
{
    stack<Node<T>*> s;
    vector<T> output;
    while (!s.empty() || root)
    {
        if (!root)
        {
            root = s.top();
            output.push_back(root->value);
            root = root->right;
            s.pop();
        }
        //Traversing left unless root is null
        if (root)
        {
            s.push(root);
            root = root->left;
        }
    }
    return output;
}

void testPreorder() 
{
  Node<int>* root = buildTree(vector<int>({1}), vector<int>({1}));
  vector<int> preorder = preorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({1}), preorder);
  delete(root);
  
  root = buildTree(vector<int>({10, 8, 3, 5, 2, 7}), vector<int>({3, 8, 5, 10, 7, 2}));
  preorder = preorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({10, 8, 3, 5, 2, 7}), preorder);
  delete(root);

  root = buildTree(vector<int>({1, 2, 3, 4, 5}), vector<int>({1, 4, 3, 2, 5}));
  preorder = preorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({1, 2, 3, 4, 5}), preorder);
  delete(root);
}


void testInorder()
{
  Node<int>* root = buildTree(vector<int>({1}), vector<int>({1}));
  vector<int> inorder = inorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({1}), inorder);
  delete(root);
  
  root = buildTree(vector<int>({10, 8, 3, 5, 2, 7}), vector<int>({3, 8, 5, 10, 7, 2}));
  inorder = inorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({3, 8, 5, 10, 7, 2}), inorder);
  delete(root);
  
  root = buildTree(vector<int>({1, 2, 3, 4, 5}), vector<int>({1, 4, 3, 2, 5}));
  inorder = inorderTraversalNoRecursion(root);
  ASSERT_EQ(vector<int>({1, 4, 3, 2, 5}), inorder);
  delete(root);
}


int main()
{
  testBuildTree();
  testPreorder();
  testInorder();
  
  Node<int>* root = buildTree(vector<int>({10, 8, 3, 5, 2, 7}), vector<int>({3, 8, 5, 10, 7, 2}));
  vector<int> preorder = preorderTraversalNoRecursion(root);
  vector<int> inorder = inorderTraversalNoRecursion(root);
  cout << "Preorder: " << preorder << endl
       << "Inorder: " << inorder << endl;
  cout << "Finished succesfully!" << endl;
}

