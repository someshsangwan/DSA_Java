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
int solve(Node* A) {
    int res=INT_MIN;
    queue<Node*>q;
    q.push(A);
    while(!q.empty()){  // we can also do the same thing with making NULL as prev question
        int n=q.size();
        int tempans=0;
        for(int i=0;i<n;i++){
            Node* temp=q.front();
            q.pop();
            tempans+=temp->key;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        res=max(res,tempans);
        
    }
    return res;
}