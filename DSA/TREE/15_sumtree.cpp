/* in this que , every node x in the tree other than the leaves , its value is equal to the sum of its left subtree value & its right subtree
value if this not happen return false; -- Sorry for my poor english */
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
pair<bool,int> issumtree(Node *root){
    if(root==NULL){
        pair<bool,int>p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int>p=make_pair(true,root->key);
        return p;
    }
    pair<bool,int>leftans=issumtree(root->left);
    pair<bool,int>rightans=issumtree(root->right);
    bool left=leftans.first;
    bool right=rightans.first;
    bool value=(root->key==leftans.second+rightans.second);
    pair<bool,int>ans;
    if(left && right && value){
        ans.first=true;
        ans.second=root->key+leftans.second+rightans.second;
         
    }
    else{
       ans.first=false;
    }
    return ans;
}