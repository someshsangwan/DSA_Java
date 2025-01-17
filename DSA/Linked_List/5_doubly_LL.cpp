using namespace std;
#include<bits/stdc++.h>
#include<iostream>
class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;

    }

};
void insert_head(Node* head,int x){
    Node*temp =new Node(x);
    temp->next=head;
    head->prev=temp;
    head=temp;
}
void insert_at_tail(Node*head,int x){
    Node* newnode=new Node(x);
    Node*curr=head;
    while(curr!=NULL){
        curr=curr->next;
    }
    curr->next=newnode;
    newnode->prev=curr;

}
void insert_at_middle(Node* head,int pos,int x){
    if(pos==1){
        insert_head(head,x);
        return;
    }
    Node*temp=head;
    int ct=1;
    while(ct<pos-1){
        temp=temp->next;
        ct++;
    }
    if(temp->next==NULL){
        insert_at_tail(head,x);
        return;
    }
    Node* newnode=new Node(x);
    newnode->next=temp->next;
    temp->next->prev=newnode;
    temp->next=newnode;
    newnode->prev=temp;




}
void deleted_node_DLL(Node* head,int pos){
    //same as singly node change bs prev node me kr dena ;


}
void print_normal(Node *head){ //its same as singly LL- just we want to print element of this LL;
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}
int get_length(Node* head){
    int len=0;
    Node* curr=head;
    while(curr!=NULL){
        len++;
        curr=curr->next;

    }
    return len;

}
int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->prev=head;
    second->next=third;
    third->prev=second;
}