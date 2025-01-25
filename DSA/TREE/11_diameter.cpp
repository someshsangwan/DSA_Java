//diameter of binary tree= is the no of node on longest  path between two nodes-- if we are getting longest path excluding root node yes it can 
//possible we can include or not ... 
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

//approach 1 -o(n^2) time complexity 
//approach 2- same code as height of binary tree;
int height(Node* node,int &ans){
        if(node==NULL){
            return 0 ;
        }
        int left=height(node->left,ans);
        int right=height(node->right,ans);
        int ans1=max(left,right)+1;
        ans=max(ans,left+right); // isme hme do node ke bich ka path dekhna h na to root add kr den ge dono lh rh me 
        return ans1; 
    }
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int ans=0;
        height(root,ans);
        return ans;
    }
};