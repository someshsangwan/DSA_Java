#include<bits/stdc++.h>
using namespace std;
#include<iostream>
class TreeNode{
    public:
    TreeNode* left;
    TreeNode* right;
    int val;
    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;

    }
};
class Solution {
public:
    int minval(TreeNode* root){
        TreeNode* temp=root;
        if(root->left==NULL){
            return root->val;
        }
        while(temp->left!=NULL){
            temp=temp->left;
        }
        return temp->val;
    }
 
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
            return root;
        }
        if(root->val==key){
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }
            if(root->left==NULL && root->right!=NULL){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            if(root->left!=NULL && root->right==NULL){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            if(root->left!=NULL && root->right!=NULL){
               int mini=minval(root->right);
               root->val=mini;
               root->right=deleteNode(root->right,mini);
               return root;
            }
            
        }
        else if(root->val>key){
            root->left= deleteNode(root->left,key);
            return root;
             
        }
        else{
             
            root->right=deleteNode(root->right,key);
            return root;
             
        }
        return root;
    }
     
};