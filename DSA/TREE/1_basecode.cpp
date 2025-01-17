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

int main() {
     Node* root= new Node(5);
     root->left=new Node(10);
     root->right=new Node(20);
}