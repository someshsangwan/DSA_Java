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
void deleteNode(Node* &head,int pos){
    if(pos==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    int ct=1;
    Node*curr=head;
    Node* prev=NULL;
    while(ct<pos){
        prev=curr;
        curr=curr->next;
        ct++;
    }
    prev->next=curr->next;
    curr->next=NULL;
    delete curr;
}
void delete_alternate(Node* &head){
    Node* curr=head;
    while(curr!=NULL && curr->next!=NULL){
        curr->next=curr->next->next;
        curr=curr->next;
    }


}
void delete_node_no_access_of_head_given_deletd_node(Node* deleted){
    deleted->data=deleted->next->data;
    deleted->next=deleted->next->next;
}


int main(){
    Node* head=new Node(3);
    Node* second=new Node(5);
    Node* third=new Node(7);
    head->next=second;
    second->next=third;
    print_normal(head);
    //deleteNode(head,1);
    //delete_alternate(head);
    delete_node_no_access_of_head_given_deletd_node(second);
    print_normal(head);

}