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
void print_recursion(Node *head){
    if(head==NULL){
        return;
    }
    cout<<head->data<<" ";
    print_recursion(head->next);
}


int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;
    cout<<"by normal iteration"<<endl;
    print_normal(head);
    cout<<"by recurion"<<endl;
    print_recursion(head);

}