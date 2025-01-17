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
// ek to sidha approach h direct inorder traversal kro or check kro ki sorted h ya nhi;
 bool f(TreeNode* root,int min,int max){
        if(root==NULL){
            return true;
        }
        if(root->val > min && root->val < max ){
            bool left=f(root->left,min,root->val);
            bool right=f(root->right,root->val,max);
            return left && right;
        }
        else{
            return false;
        }
    }
    bool isValidBST(TreeNode* root) {
        if(root==NULL){
            return true;
        }
        if(root->left==NULL && root->right==NULL){
            return true;
        }
            
         bool ans=f(root,INT_MIN,INT_MAX);
            return ans;
        
    }