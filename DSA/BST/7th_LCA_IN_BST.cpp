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

   Node* lowestCommonAncestor(Node* root, Node* p, Node* q) {
        Node* temp;
        while(root!=NULL){ //LL ki tarah traversal krenge ;
        if(root->key < p->key && root->key < q->key){
            root=root->right;
        }
        else if(root->key > p->key && root->key > q->key){
            root=root->left;
        }
        else{
            temp= root;
            break;
        }
        }
        return temp;
         
    }