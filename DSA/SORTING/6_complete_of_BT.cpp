#include<iostream>
using namespace std;
#include<bits/stdc++.h>
/*
Given the root of a binary tree, determine if it is a complete binary tree.

In a complete binary tree, every level, except possibly the last, is completely filled,
 and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.

 for better understanding see the picture 



*/
class Node{
    public:
    Node* left;
    Node* right;
    int key;
    Node(int val){
        this->key=val;
        this->left=NULL;
        this->right=NULL;

    }
};
bool isCompleteTree(Node *root) {
    queue<Node *> q;
    q.push(root);
    bool hasChild = true;
    while (!q.empty()) {

      Node *ele = q.front();
      q.pop();
      if (ele->left != NULL && !hasChild)
        return false;
      if (ele->left == NULL)
        hasChild = false;
      else
        q.push(ele->left);
      if (ele->right != NULL && !hasChild)
        return false;
      if (ele->right == NULL)
        hasChild = false;
      else
        q.push(ele->right);
    }
    return true;
  }