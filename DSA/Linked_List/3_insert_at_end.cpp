#include<bits/stdc++.h>
#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void insert_begin(Node* &head,int x){
    Node* temp=new Node(x);

    if(head==NULL){
        head=temp;
    }
    else{
    temp->next=head;
    head=temp;
    }
}
void insert_middle(Node* &head,int pos,int x){
    if(pos==1){
        insert_begin(head,x);
        return;
    }
    Node* temp= new Node(x);
    int count=1;
    Node* curr=head;
    while(count <pos-1 && curr!=NULL){
        curr=curr->next;
        count++;
    }
    temp->next=curr->next;
    curr->next=temp;
    

}
void print_normal(Node *head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}
void insert_end(Node*head,int x){
    Node* temp=new Node(x); //allocate the memory for new node
    if(head==NULL){
        head=temp;
        return;
    }
    Node* curr=head; //create a temporary node for travesal;
    while(curr->next!=NULL){
        curr=curr->next;
    }
    curr->next=temp;
}


int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;
    insert_end(head,9);
    insert_end(head,11);
    insert_end(head,13);
    insert_end(head,15);
    insert_end(head,17);
    cout<<"hi"<<endl;
    print_normal(head);
     

}