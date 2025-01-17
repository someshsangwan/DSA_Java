#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;

    Node(int d){
        this->data=d;
        this->left= NULL;
        this->right= NULL;
    }
    
};
void countleaf(Node* root, int &count){
    if(root==NULL){
        return;
    }
    if(root->left==NULL && root->right==NULL){
        count++;
    }
    countleaf(root->left,count);
    countleaf(root->right,count);
}
int main() {
     Node* root= new Node(5);
     root->left=new Node(10);
     root->right=new Node(20);
     int count=0;
     countleaf(root,count);
     cout<<count;
}