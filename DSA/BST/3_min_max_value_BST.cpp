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
// if we print inorder od bst than we will get a sorted array;
// question is that find min/max value in bst;
// approach 1- simple preorder/inorder---------------- we have dont it before;
// approach 2- take a advantage of bst;

//min vale tree ke last me left me hogi;

int min_val(Node* root){
    if(root==NULL){
        return -1;
    }
    Node* temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp->key;
}

//max value tree ke righht me last me hogi;
int max_val(Node* root){
    if(root=NULL){
        return -1;
    }
    Node* temp=root;
    while(temp->right!=NULL){
        temp=temp->right;
    }
    return temp->key;
} 