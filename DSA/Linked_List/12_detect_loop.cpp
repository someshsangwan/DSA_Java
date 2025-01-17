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
};
//floyds cycle detection method 
Node* check_loop_2(Node*head){
    if(head==NULL || head->next==NULL){
        return NULL;
    }
    Node* slow=head;
    Node* fast=head->next;
    while(slow!=NULL && fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){ 
            return slow; ;// here we can find there are a loop in out LL
        }
    }
    return NULL;

}
Node *getstarting_node(Node *head){
    if(head==NULL){
        return NULL;
    }
    Node* intersection=check_loop_2(head);
    Node* slow=head;
    intersection=intersection->next;
    while(slow!=intersection){
        slow=slow->next;
        intersection=intersection->next;
    }
    return slow;
}
void removeloop(Node* head){
    if(head==NULL){
        return;
    }
    Node* startofnode=getstarting_node(head);
    Node*temp=startofnode;
    while(temp->next!=startofnode){
        temp=temp->next;
    }
    temp->next=NULL;
}
/*
bool detect_loop_1(Node* head){ //in this method we are using o(n) space and o(n) time complexity so to optimised its solution by reducing its 
    if(head==NULL){  // space from o(n) to o(1);
        return 0;
    }
    map<Node*,bool>visited;
    Node* temp=head;
    while(temp!=NULL){
        if(visited[temp]==1){
            return true;
        }
        visited[temp]=1;
        temp=temp->next;

    }
    return false;
}*/


int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;

}