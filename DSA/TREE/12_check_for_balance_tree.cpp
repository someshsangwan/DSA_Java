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
/*A balanced binary tree is also known as height balanced tree. It is defined as binary tree in when the 
difference between the height of the left subtree and right subtree is not more than m, where m is usually equal to 1.*/
// balanced if  abs((height(left)-height(right)))<=1;

// aproach 1- o(n^2);
int height(Node* root){

}
bool isbalanced(Node*root){
    if(root==NULL){
        return true;
    }
    bool left=isbalanced(root->left);
    bool right=isbalanced(root->right);
    bool diff=abs(height(root->left)-height(root->right))<=1;  // time complexity is o(n^2) because we will travesal one node two times na;
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}

//approach 2 --o(n);
// here we will make  a pair - pair<bool,int>p -- first- bool second int height of binary tree;
pair<bool,int>isbalanced_2(Node * root){
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    pair<bool,int>left=isbalanced_2(root->left);
    pair<bool,int>right=isbalanced_2(root->right);

    bool leftans=left.first;
    bool rightans=right.first;
    bool diff=abs(left.second-right.second)<=1;
    pair<bool,int>ans;
    if(leftans && rightans && diff){
        ans.first=true;
    }
    ans.second=max(left.second,right.second)+1;
    return ans;

}