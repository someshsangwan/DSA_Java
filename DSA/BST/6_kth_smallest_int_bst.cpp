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

/*
brute force is very simple do inorder traversal we will get sorted array and return arr[k-1];
*/
// approach 2 -
// 1st smallest element we will get left side bottom na;
// to hm last me jaenge first phir aate time k-- krenge jha k==0 we will get our answer;

    void find(Node* root,int &k,int &ans){
        if(root==NULL){
            return;
        }
        find(root->left,k,ans);
        k--; // aate time k ko decrement kr rhe h ;
        //cout<<k<<" ";
        
        if(k==0){
            ans=root->key;
             
            
            return;
        }
        find(root->right,k,ans);
        
    }
    int kthSmallest(Node* root, int k) {
        int ans=0;
        find(root,k,ans);
        return ans;
        
    }