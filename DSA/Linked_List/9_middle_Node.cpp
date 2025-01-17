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
int getlength(Node*head){
    Node*temp=head;
    int ct=0;
    while(temp!=NULL){
        temp=temp->next;
        ct++;
    }
    return ct;
}
Node* middleNode_1(Node*head){
    int len=getlength(head);
    int ans=(len/2)+1;
    int ct=0;
    Node*temp=head;
    while(ct<ans-1){
        temp=temp->next;
        ct++;
    }
    return temp;
}
Node* middleNode_2(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    if(head->next->next==NULL){
        return head->next;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;

        
    }
    return slow;
}
 
 
int main(){ 
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;
    Node* middle=middleNode_1(head);
    cout<<middle->data<<endl;
    //print_normal(head);
    //cout<<reverse(head)<<endl;
}