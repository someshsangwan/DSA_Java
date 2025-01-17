/*
Input 1:

    1
   / \
  2   2              output 1=1;
 / \ / \
3  4 4  3
Input 2:

    1
   / \             outout2=0; bcz 2'left is null but 2'right is not null
  2   2
   \   \
   3    3





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
bool isidentical(Node * root1 , Node * root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2 !=NULL){
        return false;
    }
    if(root1 != NULL && root2==NULL){
        return false;
    }
    bool left=isidentical(root1->left,root2->right);/*  bs yhi chnage hua h*/
    bool right=isidentical(root1->right,root2->left);// here only
    bool value=((root1->key)==(root2->key));
    if(left && right && value){
        return true;
    }
    else{
        return false;
    }


}
int isSymmetric(Node* root) {
    if(root==NULL){
        return 1;
 
    return isidentical(root->left,root->right);
    
}
}