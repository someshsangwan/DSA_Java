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
void rightview(Node*root,vector<int>&ans,int level){  // pass it with value 0;
    if(root==NULL){
        return;
    }
    if(level==ans.size()){ //it means it is the firat element at right side at that level
        ans.push_back(root->key);
    }
    rightview(root->right,ans,level+1);
    rightview(root->left,ans,level+1);
}