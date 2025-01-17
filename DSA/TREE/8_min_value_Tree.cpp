//hello guys myself somesh sangwan.....a student of IIT RoPAR-----------------------------
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
void inorder(Node* root,int &mini){
    if(root==NULL){
        return;
    }
    inorder(root->left,mini);
    mini=min(mini,root->key);
    inorder(root->right,mini);
}
int min_value(Node* root){
    if(root==NULL){
        return -1;
    }
    int mini=INT_MAX;
    inorder(root,mini);
    return mini;
}