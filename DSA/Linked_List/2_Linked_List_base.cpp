#include<bits/stdc++.h>
using namespace std;

class Node{
public:
    int data;
    Node* next;
  

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
    
};

int main() {
     Node* root= new Node(5);
}