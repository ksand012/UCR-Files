#include <iostream>
#include <gtest/gtest.h>
#include <vector>
#include <stack>
#include "helper.hh"

using namespace std;

template<typename T>
bool find(Node<T>* curr, Node<T>* x)
{
  if(curr == NULL)
  {
    return false;
  }
  
  if(curr == x)
  {
    return true; 
  }
  if(curr->right)
  {
    find(curr->right, x);
  }
  if(curr->left)
  {
    find(curr->left, x);
  }

}

template <typename T>
T goleft(Node<T>* curr)
{
  while (curr -> left != NULL)
  {
    curr = curr->left;
  }
  return curr->value; 
}

template<typename T>
bool right(Node<T>* top, Node<T>* curr)
{
  if(top == curr)
  {
    return false; 
  }
  
  if(top->right != NULL)
  {
    top = top->right;
    return (find(top, curr));
  }
  else
  {
    return false;
  }
}



template <typename T>
T Next(Node<T>* curr, Node<T>* root)
{
  Node<T>* org = curr; 
  if(curr == NULL)
  {
    return 0; 
  }
  
  if(root == NULL)
  {
    return 0; 
  }
  if(right(root, curr) == true)
  {
    if(curr->right == NULL && curr->left == NULL)
    {
      return 0; 
    }
    
    if(curr->right)
    {
      return curr->right->value; 
    }
  }
  else
  {
    if(curr->right)
    {
      return goleft(curr->right); 
    }
    
    if(curr->right == NULL && right(curr->parent, curr))
    {
      curr = curr->parent; 
      while(curr != NULL && curr->left == NULL)
      {
        curr = curr->parent; 
      }
      return curr->parent->value; 
    }
    
    if(curr->right == NULL && !right(curr->parent, curr))
    {
      return curr->parent->value; 
    }
  }
  
  return 0; 
}

/*template <typename T>
Node<T>* findNext(Node<T>* root, Node<T>* node) 
{
    while( (root != NULL) || (root->left != NULL && root->right != NULL) )
    {

        if( (root->left != NULL && root->left->value == node->value) || (root->right != NULL && root->right->value == node->value))
            return root;

        if(root->value > node->value)
            root = root->left;

        if(root->value < node->value)
            root = root->right;
       
    }
    /*if(node->right != NULL)
    {
        cout << node->right->value << endl;
        return node->right;
    }
    else if(node->parent->left == node)
    {
        node = node->parent;
        cout << node << endl;
        return node;
        
    }
    else if(node == node->parent->right && node->left != NULL)
    {
        node = node->left;
        cout << node->value << endl;
        return node;
        
    }
    else
    {
        node = node->parent;
        node= node->parent;
        
        cout << node->value << endl;
        return node;
    }
    */
//}

template <typename T>
vector<T> preorderTraversalNoRecursion(Node<T>* root) 
{
    stack<Node<T>*> s;
    vector<T> output;
    /*Root is NULL, nothing to do.*/
    if (!root)
        return output;
    /*Push root*/
    s.push(root);
    while (!s.empty())
    {
        /*Pop the top element*/
        Node<T>* tmpPtr = s.top();
        output.push_back(tmpPtr->value);
        s.pop();
        /*Go right before going left as we are using a stack.*/
        if (tmpPtr->right)
            s.push(tmpPtr->right);
        if (tmpPtr->left)
            s.push(tmpPtr->left);
    }
    return output;
  
  // vector<T> preorder;
  // if (root == NULL)
  //   return preorder;
  // // 1. root
  // preorder.push_back(root->value);
  // // 2. Preorder left
  // vector<T> preorderLeft = preorderTraversalNoRecursion(root->left);
  // preorder.insert(preorder.end(), preorderLeft.begin(), preorderLeft.end());
  // // 3. Preorder right
  // vector<T> preorderRight = preorderTraversalNoRecursion(root->right);
  // preorder.insert(preorder.end(), preorderRight.begin(), preorderRight.end());
  // return preorder;
}

template <typename T>
vector<T> inorderTraversalNoRecursion(Node<T>* root) 
{
    stack<Node<T>*> s;
    vector<T> output;
    while (!s.empty() || root)
    {
        /*If root is NULL, we need to pop from top of the stack
        and print it's value. Then traverse the right sub-tree*/
        if (!root)
        {
            root = s.top();
            output.push_back(root->value);
            root = root->right;
            s.pop();
        }
        /*Keep traversing left unless root is NULL*/
        if (root)
        {
            s.push(root);
            root = root->left;
        }
    }
    return output;
  
  // vector<T> inorder;
  // if (root == NULL)
  //   return inorder;
  // // 1. Inorder left
  // vector<T> inorderLeft = inorderTraversalNoRecursion(root->left);
  // inorder.insert(inorder.end(), inorderLeft.begin(), inorderLeft.end());
  // // 2. root
  // inorder.push_back(root->value);
  // // 3. Inorder right
  // vector<T> inorderRight = inorderTraversalNoRecursion(root->right);
  // inorder.insert(inorder.end(), inorderRight.begin(), inorderRight.end());
  // return inorder;
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
    
  Node<int>* node = root->left->right;
  Node<int>* nextNode = findNext(root, node);
  cout << nextNode->value << endl;
}

