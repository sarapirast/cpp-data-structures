#include <iostream>
#include <limits.h>
#include <map>
#include <set>
#include <string>
#include <vector>
using namespace std;

// A class for a binary tree node. No need to modify.
class TreeNode {
public:
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  ~TreeNode() { delete left; delete right; }
};

// Write a class for BST with the following methods.
// Implement all the methods of the class in the q.cc file.
// Note that all functions should be implemented recursively.

// Also note that:
// 1. The root of the BST is a private member of the class.
// 2. Each method has a helper function that is called recursively from the
// public method with the same name. The helper function has an additional
// parameter to help with the recursion.
class Bst {
public:
  // Non-parameterized constructor: already defined. No need to modify.
  Bst() {}

  // Destructor: already defined. No need to modify.
  ~Bst() { delete root_; }

  // Parameterized constructor: creates a BST from the given input.
  Bst(std::vector<int> &input);

  // Inserts a value into the BST.
  void Insert(int val);

  // Returns the root of the BST.
  TreeNode *GetRoot();

  // Returns the height of the BST.
  int GetHeight();

  // Returns the number of nodes in the BST.
  int GetSize();

  // Returns the minimum value in the BST.
  int GetMin();

  // Returns the maximum value in the BST.
  int GetMax();

  // Returns the node that contains the given value and nullptr if the value is
  // not found.
  TreeNode *Find(int val);

  // Returns the inorder traversal of the BST.
  std::vector<int> InorderTraversal();

  // Returns the preorder traversal of the BST.
  std::vector<int> PreorderTraversal();

  // Returns the postorder traversal of the BST.
  std::vector<int> PostorderTraversal();

  // Returns the level order traversal of the BST.
  std::vector<int> LevelOrderTraversal();

private:
  // Helper function to insert a value into the BST.
  void Insert(TreeNode *&root, int val);

  // Helper function to get the height of the BST.
  int GetHeight(TreeNode *root);

  // Helper function to get the number of nodes in the BST.
  int GetSize(TreeNode *root);

  // Helper function to get the minimum value in the BST.
  int GetMin(TreeNode *root);

  // Helper function to get the maximum value in the BST.
  int GetMax(TreeNode *root);

  // Helper function to find a value in the BST.
  TreeNode *Find(TreeNode *root, int val);

  // Helper function to get the inorder traversal of the BST.
  void InorderTraversal(TreeNode *root, std::vector<int> &result);

  // Helper function to get the preorder traversal of the BST.
  void PreorderTraversal(TreeNode *root, std::vector<int> &result);

  // Helper function to get the postorder traversal of the BST.
  void PostorderTraversal(TreeNode *root, std::vector<int> &result);

  // The root of the BST.
  TreeNode *root_ = nullptr;
};
