using namespace std;
#include<bits/stdc++.h>
#include<iostream>
// isme jaise 1 2 3 4 5 to k=3 h to resulntant 3 2 1 5 4 bhi kr dega ;
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
Node* reverse_k(Node*head,int k){
    if(head==NULL){
        return NULL;
    }
    Node* prev=NULL;
    Node*ford;
    Node* curr=head;
    int ct=0;
    while(ct<k && curr!=NULL){
        ford=curr->next;
        curr->next=prev;
        prev=curr;
        curr=ford;
        ct++;
    }
    if(ford!=NULL){
        head->next=reverse_k(ford,k);     
    }
    return prev;
}
