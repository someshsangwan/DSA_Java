#include<bits/stdc++.h>
using namespace std;
#include<iostream>
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
void deleteathead(Node*head){
    Node*temp=head;
    while(temp->next!=head){
        temp=temp->next;
    }
    Node* todelete=head;
    temp->next=head->next;
    head=head->next;
    delete todelete;
}
void deletion(Node* head,int pos){
    if(pos==1){
        deleteathead(head);
        return;
    }
    Node*temp=head;
    int ct=1;
    while(ct!=pos-1){
        temp=temp->next;
        ct++;
    }
    Node *todelete=temp->next;
    temp->next=temp->next->next;
    delete todelete;
}
};
void print_it(Node*head){
    Node* temp=head;
    do{
        cout<<temp->data<<" ";
        temp=temp->next;

    }while(temp!=head);
    cout<<endl;
}
int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;
    third->next=head;
}