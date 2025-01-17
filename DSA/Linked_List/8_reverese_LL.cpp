using namespace std;
#include<bits/stdc++.h>
#include<iostream>
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void print_normal(Node *head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}

Node* reverse(Node*head){
    Node*prev=NULL;
    Node* curr=head;
    Node* ford;
    while(curr!=NULL){
        ford=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ford;

    }
    return prev;
}
 
int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;
    print_normal(head);
    Node* afterrevese=reverse(head);
    print_normal(afterrevese);
    //cout<<reverse(head)<<endl;
}