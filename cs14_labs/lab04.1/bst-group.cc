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
	Node<T> *left, *right;
	Node() : left(NULL), right(NULL) {}
	Node(const T& x) : value(x), left(NULL), right(NULL) {}
};

template <typename T>
class BST {
  Node<T>* root;
  
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
public:
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
  
  bool insert(const T& x) {
  	Node<T>** p = searchNode(x);
  	if (*p != NULL)
  		return false; // Element found in the tree but we do not currently support duplicate values
  	// The pointer falled off the tree, the new value should be inserted at
  	// the current pointer position
  	(*p) = new Node<T>();
  	(*p)->value = x;
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
