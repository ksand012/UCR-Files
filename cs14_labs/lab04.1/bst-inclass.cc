#include <iostream>
#include <cstdlib>
#include <gtest/gtest.h>
#include <stack>
#include <string>
#include <algorithm>
#include <random>

using namespace std;

template <typename T>
struct Node {
	T value;
	int size;
	int rank;
	Node<T> *left, *right;
	Node() : left(NULL), right(NULL), size(1), rank(0) {}
	Node(const T& x) : value(x), left(NULL), right(NULL),size(1),rank(0) {}
};

template <typename T>
class BST {
  Node<T>* root;

public:  
  Node<T>** searchNode(const T& x) {
  	Node<T>** p = &root;
  	while (*p != NULL) {
  		if ((*p)->value < x)
  			p = &((*p)->right);
  		else if (x < (*p)->value)
  			p = &((*p)->left);
  		else
  		    return p;  // Element found in the tree, return it
  	}
  	return p; // Element not found in the tree, return a pointer to where it is supposed to be
  }

  BST() : root(NULL) {}
  ~BST() {
  	// Delete all nodes in the tree
  	stack<Node<T>*> toDelete;
  	toDelete.push(root);
  	while (!toDelete.empty()) {
  		Node<T>* node = toDelete.top();
  		toDelete.pop();
  		if (node != NULL) {
  		  delete node;
  		  toDelete.push(node->left);
  		  toDelete.push(node->right);
  		}
  	}
  }
  
  int size(Node<T>* root, int &count) {
	if(root == NULL) {
		return count;
	}
	count++;
	size(root->left, count);     // Visit left subtree
	size(root->right, count);    // Visit right subtree
  }
  
  int rank_2(Node<T>* root, int &count, T key) {
	// base condition for recursion
	// if tree/sub-tree is empty, return and exit
	if(root == NULL) {
		return count;
	}
	
	if (root->value < key) {
		count++;
	}

	rank_2(root->left, count, key);     // Visit left subtree
	rank_2(root->right, count, key);    // Visit right subtree
  }
  
  /*int rank(Node<T>* root, const T x)
  {
  	Node<T>** p = searchnode(x);
  	
  }*/
  
  /*int size(Node<T>* root, int& count = 0)
  {
  	Node<T>* p = root;
  	//int temp = 0;
  	if((p) == NULL)
  	{
  		return count;
  	}
  	else
  	{
  		count++;
  		return size(((p) -> left), count) + size(((p) -> right), count);
  	}
  	*/
  	//while(*p->left != NULL)
  	//{
  		//temp++;
  	//}
  	
  	//if()
  	//max(HEIGHT(left), HEIGHT(right)) + 1;
  //}
  
  bool insert(const T& x) {
  	Node<T>** p = searchNode(x);
  	if (*p != NULL)
  		return false; // Element found in the tree but we do not currently support duplicate values
  	// The pointer falled off the tree, the new value should be inserted at
  	// the current pointer position
  	(*p) = new Node<T>();
  	(*p)->value = x;
  	int count = 0;
  	(*p)->size = size((*p), count);
  	//cout << "Size is: " << ((*p)->size) << endl;
  	return true;
  }
  
  bool search(const T& x) {
  	Node<T>** p = searchNode(x);
  	return *p != NULL;
  }
  
  bool erase(const T& x) {
  	Node<T>** p = searchNode(x);
  	
  	if (*p == NULL){
  		return false; 
  		}
  		
  		// Element not found in the tree
    	// Check the three cases
	if ((*p)->left == NULL && (*p)->right == NULL) {
		// change the parent node to NULL and delete the leaf.
		// TODO Case 1: Deleting a leaf node
		
		Node<T>* temp = *p;
		*p = NULL;
		delete temp;
	
		return true;
	}
		else if ((*p)->left == NULL || (*p)->right == NULL) {
			Node<T>* temp = *p;
			if((*p)->right != NULL){
				*p = (*p)->right;
			}
			else if((*p)->right == NULL){
				*p = (*p)->left;
			}
			delete temp;
			
			return true;
		// TODO Case 2: Deleting a node with one child
		//make temp to node then change parent parent of node to point to child of node and delete parent 
	} else {
			Node<T>* temp = *p;
			temp->right->left = (*p)->left;
			*p = (*p)->right;
			delete temp;
			return true;
		// return true;
		// TODO Case 3: Deleting a node with two children
	}
	return false;
  }
  
  bool empty() {
  	return root == NULL;
  }
};

int main(){
	// Simple tests for the binary search tree
	BST<int> bst;
	// Test insert and search
	bst.insert(3);
	bst.insert(2);
	bst.insert(5);
	
	//DEBUG
	/*int count = 0;
	cout << "Printing..." << endl;
	cout << bst.size(*(bst.searchNode(3)), count) << endl;
	*/
	
	//DEBUG
	/*int count = 0;
	cout << "Printing..." << endl;
	cout << bst.rank_2(*(bst.searchNode(5)), count, 5) << endl;
	*/
	
	EXPECT_TRUE(bst.search(3));
	EXPECT_TRUE(bst.search(2));
	EXPECT_TRUE(bst.search(5));
	// Test delete a leaf node
	EXPECT_TRUE(bst.erase(2));
	EXPECT_FALSE(bst.search(2));
	// Test deleting a node with one child
	bst.insert(4);
	EXPECT_TRUE(bst.erase(5));
	EXPECT_FALSE(bst.search(5));
	// Test deleting a node with two children
	bst.insert(2);
	bst.insert(5);
	EXPECT_TRUE(bst.erase(3));
	EXPECT_FALSE(bst.search(3));
	
	// BST random test. Insert the values 1-20 in a random order
	BST<int> random_bst;
	vector<int> values;
	for (int i = 1; i <= 20; i++) {
		values.push_back(i);		
	}
	auto rng = std::default_random_engine {};
	std::shuffle(std::begin(values), std::end(values), rng);
	for (auto x : values) {
		random_bst.insert(x);
	}
	// Make sure that all the elements are in the tree	
	for (int i = 1; i <= 20; i++) {
		EXPECT_TRUE(random_bst.search(i));
	}
	// Delete all the elements in the tree
	for (int i = 1; i <= 20; i++) {
		EXPECT_TRUE(random_bst.erase(i));
	}
	// Make sure that the tree is empty
	EXPECT_TRUE(random_bst.empty());
	return 0;

}
