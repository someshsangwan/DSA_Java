/*
search a element in bst return true if that elemennt is present in bst 
else return false;
*/
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
// approach first -- normal traversal like inorder,preorder,postorder---
// approach 2 --- binary search
// we can do by using recursion as well as iterative approach;
bool search(Node* root,int x){
    if(root==NULL){
        return false;
    }
    if(root->key==x){
        return true;
    }
    if(root->key>x){
        search(root->left,x);
    }
    else{
        search(root->right,x);
    }
}

// iterative approach
bool search_2(Node*root,int x){
    Node* temp=root; //ye ek type ka LL ho gya na to hm uske jaise hi kr lenge 
    while(temp!=NULL){
        if(temp->key==x){
            return true;
        }
        if(temp->key>x){
            temp=temp->left;
        }
        else{
            temp=temp->right;
        }
    }
    return false;
}