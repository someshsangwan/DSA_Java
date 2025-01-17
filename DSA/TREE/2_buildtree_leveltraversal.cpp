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

Node* buildtree(Node* root){
    queue<Node*>q;
    cout<<"enter the root node data"<<endl;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter the left node for "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }
        cout<<"Enter the right node for "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }
    return root;     
}
int main() {
     Node* root=NULL;
     root=buildtree(root);
}