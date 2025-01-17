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
bool check_LL(Node* head){
    if(head==NULL || head->next==NULL){
        return 0;
    }
    Node *temp=head->next;
    while(temp!=NULL && temp!=head){
        temp=temp->next;
    }
    if(temp==NULL){
        return 0;
    }
    else{
        return 1;
    }
}
 

int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;
    cout<<check_LL(head)<<endl;
    cout<<"Hi"<<endl;

}