//Linked is sorted and remove duplicate node 
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
Node* remove_duplicate(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node*temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if((temp->data)==(temp->next->data)){
            Node* todelete=temp->next;
            temp->next=temp->next->next;
            delete todelete;
        }
        else{
            temp=temp->next;
        }

    }
    return head;
}


int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;

}