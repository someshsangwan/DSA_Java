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
vector<vector<int> >zigzagLevelOrder(Node* A) {
    vector<vector<int>>res;
    queue<Node*>q;
    q.push(A);
    bool left_to_right=true;
    while(!q.empty()){
        int n=q.size();
        vector<int>t(n);
        for(int i=0;i<n;i++){
            Node* temp=q.front();
            q.pop();
            int index;
            if(left_to_right==true){
                index=i;
            }
            else{
                index=n-i-1;
            }
            t[index]=temp->key;
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }
        res.push_back(t);
        left_to_right=!left_to_right;
    }
    return res;
}