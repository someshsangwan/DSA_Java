//minimum depth of a binary tree is the length of shortest path of all paths from root to leaf node;\
#include<bits/stdc++.h>
using namespace std;
#include<bits/stdc++.h>
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
int mindepth(Node* root){
    if(root==NULL){  //in the case of , in function call we get NULL node 
        return 0;
    }
    if(root->left==NULL && root->right==NULL){
        return 1; //leaf node h bhai ;
    }
    int left=INT_MAX;   // assume if we have only left child of any node then ans =min(2,INT_MAX)=2;
    int right=INT_MAX;
    if(root->left){
        left=mindepth(root->left)+1;  //+1 because of that root node;
    }
    if(root->right){
        right=mindepth(root->right)+1;
    }
    int ans=min(left,right);
    return ans;
}