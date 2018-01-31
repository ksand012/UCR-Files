using namespace std;

template <typename T>
struct Node {
  T value;
  Node<T>* left;
  Node<T>* right;
  Node<T>* parent;
  
  Node(const T& val) {
    value = val; left = NULL; right = NULL; parent = NULL;
  }
  
  ~Node() {
    delete(left);
    delete(right);
    if(parent == NULL) delete(parent);
  }
};


template <typename T>
Node<T>* construct(const vector<T>& preorder, int preStart, int preEnd, const vector<T>& inorder, int inStart, int inEnd, Node<T>* parent){
  if(preStart>preEnd||inStart>inEnd){
    return NULL;
  }
  T val = preorder[preStart];
  Node<T>* p = new Node<T>(val);
  //find parent element index from inorder
  int k=0;
  for(int i=0; i<inorder.size(); i++){
    if(val == inorder[i]){
      k=i;
      break;
    }
  }
  p->parent = parent;
  p->left = construct(preorder, preStart+1, preStart+(k-inStart), inorder, inStart, k-1, p);
  p->right= construct(preorder, preStart+(k-inStart)+1, preEnd, inorder, k+1 , inEnd, p);
  return p;
}

// Code courtesy of https://www.programcreek.com/2014/06/leetcode-construct-binary-tree-from-preorder-and-inorder-traversal-java/
template <typename T>
Node<T>* buildTree(const vector<T>& preorder, const vector<T>& inorder) {
  int preStart = 0;
  int preEnd = preorder.size()-1;
  int inStart = 0;
  int inEnd = inorder.size()-1;
  Node<T>* parent = NULL;
  return construct(preorder, preStart, preEnd, inorder, inStart, inEnd, parent);
}

void testBuildTree() {
  Node<int>* root = buildTree(vector<int>({1}), vector<int>({1}));
  ASSERT_EQ(root->value, 1);
  ASSERT_TRUE(root->left == NULL);
  ASSERT_TRUE(root->right == NULL);
  delete(root);

  root = buildTree(vector<int>({1, 2, 3}), vector<int>({2, 1, 3}));
  ASSERT_EQ(1, root->value);
  ASSERT_FALSE(root->left == NULL);
  ASSERT_EQ(2, root->left->value);
  ASSERT_FALSE(root->right == NULL);
  ASSERT_EQ(3, root->right->value);
  delete(root);
  
  root = buildTree(vector<int>({1, 2, 3, 4, 5}), vector<int>({1, 4, 3, 2, 5}));
  ASSERT_EQ(1, root->value);
  ASSERT_TRUE(root->left == NULL);
  ASSERT_FALSE(root->right == NULL);
  ASSERT_EQ(2, root->right->value);
  ASSERT_FALSE(root->right->left == NULL);
  ASSERT_EQ(3, root->right->left->value);
  ASSERT_FALSE(root->right->left->left == NULL);
  ASSERT_EQ(4, root->right->left->left->value);
  ASSERT_FALSE(root->right->right == NULL);
  ASSERT_EQ(5, root->right->right->value);
  delete(root);
}

// Next function courtesty of https://stackoverflow.com/questions/10750057/how-to-print-out-the-contents-of-a-vector
template <typename T>
std::ostream& operator<< (std::ostream& out, const std::vector<T>& v) {
  if ( !v.empty() ) {
    out << '[';
    std::copy (v.begin(), v.end(), std::ostream_iterator<T>(out, ", "));
    out << "\b\b]";
  }
  return out;
}