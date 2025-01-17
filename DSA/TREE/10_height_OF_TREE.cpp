// height of binary tree means longest path beetween root node to leaf node;
#include<bits/stdc++.h>
using namespace std;
#include<iostream>
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
int  height_of_bt(Node* root){
    if(root==NULL){
        return 0;
    }
    int left=height_of_bt(root->left);
    int right=height_of_bt(root->right);
    int ans=max(left,right)+1;
    return ans;
}