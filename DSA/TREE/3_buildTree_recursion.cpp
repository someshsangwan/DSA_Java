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
Node* buildtree(Node* root){
    cout<<"enter the root data"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    if(data==-1){
        return NULL;
    }
    
    cout<<"enter the element that you want to add left of "<<root->key<<endl;
    root->left=buildtree(root->left);
    cout<<"enter the element that you want to add right of "<<root->key<<endl;
    root->right=buildtree(root->right);

    return root;

    

}
int main(){
    Node*root=buildtree(root);
}