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
vector<int> levelorder(Node* root){
    vector<int>v;
    queue<Node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){   
        Node* temp=q.front();         
        q.pop();
        v.push_back(temp->key);
        if(temp->right){
        q.push(temp->right);
        }
        if(temp->left){
        q.push(temp->left);
        }
       
    }
    reverse(v.begin(),v.end());
    return v;

}
int main(){

}