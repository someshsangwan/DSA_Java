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
//there are total 3 approaches -
// 1) use to while loop - time complexity is o(n^2);
// 2) sort the LL and perform as a prev q.- time complexity o(nlogn);
// 3) use map o(n) space and o(n) time complexity o(n);

Node* remove_duplicate(Node*head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    map<int,bool>m;
    Node* temp=head;
    while(temp!=NULL && temp->next!=NULL){
        if(m[temp->next->data]==1){
            temp->next=temp->next->next;
        }else{
        m[temp->data]=1;
        temp=temp->next;
        }

    }
    return head;

}
void print_normal(Node *head){
    Node* curr=head;
    while(curr!=NULL){
        cout<<curr->data<<" ";
        curr=curr->next;
    }cout<<endl;
}
void insert_end(Node*head,int x){
    //cout<<"heloooooooo"<<endl;
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
    insert_end(head,3);
    insert_end(head,7);
    insert_end(head,15);
    insert_end(head,9);
    print_normal(head);
    Node* main=remove_duplicate(head);
    print_normal(main);


}