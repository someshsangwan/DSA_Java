// binary search o(logn);
// linear search o(n);
/*
bst also  called ordered/sorted binary  tree;
for every node , its left node value always less than and right node value is always greater then this node
                   8
                 /    \
                6     10
               / \   /  \
             2   7  9    13

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
Node*insert_node(Node* root,int d){
    if(root==NULL){
        root=new Node(d);
        return root;
    }
    if(d>root->key){
        root->right=insert_node(root->right,d);
    }
    else if(root->key==d){
        return root;
    }
    else{
        root->left= insert_node(root->left,d);
    }
    return root;
}
void take_input(Node* &root){
    int data;
    cin>>data;
    while(data!=-1){
        root=insert_node(root,data); 
        cin>>data;
        
    }
}
void in_order_traversal(Node* root) {
    if (root == NULL) return;
    in_order_traversal(root->left);
    cout << root->key << " ";
    in_order_traversal(root->right);
}
int main(){
    Node* root=NULL;
    take_input(root);
    in_order_traversal(root);
}