#include "q.h"

#include <cmath>
#include <iostream>
#include <list>
#include <string>
#include <vector>
#include <queue>

// TODO:
// 1. Implement the the functions in q.h.
// 2. Write some unit tests for them in student_test.cc
 // Parameterized constructor: creates a BST from the given input.
  Bst::Bst(std::vector<int> &input){
    for (int val:input){
      Insert(val);
    }
  }

  // Inserts a value into the BST.
  void Bst::Insert(int val){
    Insert(root_,val);
  }

  // Returns the root of the BST.
  TreeNode *Bst::GetRoot(){
    return root_;
  }

  // Returns the height of the BST.
  int Bst::GetHeight(){
    return GetHeight(root_);
    }

  // Returns the number of nodes in the BST.
  int Bst::GetSize(){
    return GetSize(root_);
  }

  // Returns the minimum value in the BST.
  int Bst::GetMin(){
    return GetMin(root_);
  }

  // Returns the maximum value in the BST.
  int Bst::GetMax(){
    return GetMax(root_);
  }

  // Returns the node that contains the given value and nullptr if the value is
  // not found.
  TreeNode *Bst::Find(int val){
    return Find(root_,val);
  }

  // Returns the inorder traversal of the BST.
  std::vector<int> Bst::InorderTraversal(){
    std::vector<int> res;
    InorderTraversal(root_, res);
    return res;
  }

  // Returns the preorder traversal of the BST.
  std::vector<int> Bst::PreorderTraversal(){
    std::vector<int> res;
    PreorderTraversal(root_, res);
    return res;
  }
// Returns the postorder traversal of the BST.
  std::vector<int> Bst::PostorderTraversal(){
    std::vector<int> res;
    PostorderTraversal(root_, res);
    return res;
  }

  // Returns the level order traversal of the BST.
  std::vector<int> Bst::LevelOrderTraversal(){
    std::vector<int> res;
    if (!root_) return res;
    std::queue<TreeNode *> qu;
    qu.push(root_);
    while (!qu.empty()) {
      TreeNode *cur= qu.front();
      qu.pop();
      res.push_back(cur->val);
      if (cur->left) qu.push(cur->left);
      if (cur->right) qu.push(cur->right);
    }
  return res;
  }

  // Helper function to insert a value into the BST.
  void Bst::Insert(TreeNode *&root, int val){
    if (!root) {
      root= new TreeNode(val);
      return;
    }
    if (val<root->val) {
      Insert(root->left, val);
    }
    else{
      Insert(root->right, val);
    }
  }

  // Helper function to get the height of the BST.
  int Bst::GetHeight(TreeNode *root){
    if (!root) return 0;
    return 1+std::max(GetHeight(root->left), GetHeight(root->right));
  }

  // Helper function to get the number of nodes in the BST.
  int Bst::GetSize(TreeNode *root){
    if (!root) return 0;
    return 1+GetSize(root->left)+ GetSize(root->right);
  }

  // Helper function to get the minimum value in the BST.
  int Bst::GetMin(TreeNode *root){
    if (!root_) return INT_MAX;
    if (!root->left) return root->val;
    return GetMin(root->left);
  }

  // Helper function to get the maximum value in the BST.
  int Bst::GetMax(TreeNode *root){
    if (!root_) return INT_MIN;
    if (!root->right) return root->val;
    return GetMax(root->right);   
  }

  // Helper function to find a value in the BST.
  TreeNode *Bst::Find(TreeNode *root, int val){
    if (!root) return nullptr;
    if (val== root->val) return root;
    if (val < root->val) return Find(root->left, val);
    return Find(root->right, val);  
  }

  // Helper function to get the inorder traversal of the BST.
  void Bst::InorderTraversal(TreeNode *root, std::vector<int> &result){
    if (!root) return;
    InorderTraversal(root->left, result);
    result.push_back(root->val);
    InorderTraversal(root->right, result);
  }

  // Helper function to get the preorder traversal of the BST.
  void Bst::PreorderTraversal(TreeNode *root, std::vector<int> &result){
    if (!root) return;
    result.push_back(root->val);
    PreorderTraversal(root->left, result);
    PreorderTraversal(root->right, result);
  }

  // Helper function to get the postorder traversal of the BST.
  void Bst::PostorderTraversal(TreeNode *root, std::vector<int> &result){
    if (!root) return;
    PostorderTraversal(root->left, result);
    PostorderTraversal(root->right, result);
    result.push_back(root->val);
  }
