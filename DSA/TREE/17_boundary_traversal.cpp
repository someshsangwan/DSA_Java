/*in this question we have to print booundry element of a tree 
approach--algorithm
1) first we print left part of a tree exclusive leaf node;   // hello kidz these three part can be asked indivisual in interview ; 
2) print  leaf node 
3) print reverse right part of a tree exclusive leaf node */
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
void traversalleft(Node*root,vector<int>&v){
    if(root==NULL|| root->left==NULL && root->right==NULL){
        return ;

    }
    v.push_back(root->key);
    if(root->left){
        traversalleft(root->left,v);
    }
    else{
        traversalleft(root->right,v);
    }
}
void traversalleaf(Node* root,vector<int>&v){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        v.push_back(root->key);
    }
    traversalleaf(root->left,v);
    traversalleaf(root->right,v);
}

void traversalright(Node* root,vector<int>&v){
    if(root==NULL || root->left==NULL && root->right==NULL ){
        return;
    }
    if(root->right){
        traversalright(root->right,v);
    }
    else{
        traversalright(root->left,v);
    }
    v.push_back(root->key); // we need reverse na to hm aate time push krenge ;
}
 

vector<int>boundary(Node *root){
    vector<int>ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->key);
    traversalleft(root->left,ans); // because we already pushed root data so we call from root ->left;
    traversalleaf(root->left,ans);//leaf node of left subtree;  // we can write them by merge traversalleaf(root->data)
    traversalleaf(root->right,ans);// leaf node from right subtree;
    traversalright(root->right,ans);//right boundary node
    return ans;


}