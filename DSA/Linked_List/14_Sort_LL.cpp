// take a vector , put all values and sort array & put again alal values 
//time -> o(n)+o(nlogn)(sort(arr.begin(),arr.end()))+o(n)  , space o(n);
//time =o(nlogn) & space o(n);

//lets do it in only o(1) space and o(nlogn) time 
//for recursive call space is sort LL is o(logn);

//Time Complexity: O(N log N)where N is the number of nodes in the linked list. 
//Finding the middle node of the linked list requires traversing it linearly taking O(N) 
//time complexity and to reach the individual nodes of the list, it has to be split log N times 
//(continuously halve the list until we have individual elements).

#include <iostream>
#include <bits/stdc++.h> 

using namespace std;

// Node class represents a
// node in a linked list
class Node {
public:
    // Data stored in the node
    int data;
    
    // Pointer to the next node in the list
    Node* next;

    // Constructor with both data and
    // next node as parameters
    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    // Constructor with only data as a
    // parameter, sets next to NULL
    Node(int data1) {
        data = data1;
        next = NULL;
    }
};

// Function to merge two sorted linked lists
Node* mergeTwoSortedLinkedLists(Node* list1, Node* list2) {
    // Create a dummy node to serve
    // as the head of the merged list
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    // Traverse both lists simultaneously
    while (list1 != NULL && list2 != NULL) {
        // Compare elements of both lists and
        // link the smaller node to the merged list
        if (list1->data <= list2->data) {
            temp->next = list1;
            list1 = list1->next;
        } else {
            temp->next = list2;
            list2 = list2->next;
        }
        // Move the temporary pointer
        // to the next node
        temp = temp->next; 
    }

    // If any list still has remaining
    // elements, append them to the merged list
    if (list1 != NULL) {
        temp->next = list1;
    } else {
        temp->next = list2;
    }
    // Return the merged list starting 
    // from the next of the dummy node
    return dummyNode->next;
}

// Function to find the middle of a linked list
Node* findMiddle(Node* head){
    // If the list is empty or has only one node
    // the middle is the head itself
    if (head == NULL || head->next == NULL) {
        return head;
    }

    // Initializing slow and fast pointers
    Node* slow = head;
    Node* fast = head->next;

    // Move the fast pointer twice as fast as the slow pointer
    // When the fast pointer reaches the end, the slow pointer
    // will be at the middle
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

// Function to perform merge sort on a linked list
Node* sortLL(Node* head){
    // Base case: if the list is empty or has only one node
    // it is already sorted, so return the head
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    // Find the middle of the list using the findMiddle function
    Node* middle = findMiddle(head);
    
    // Divide the list into two halves
    Node* right = middle->next;
    middle->next = NULL;
    Node* left = head;
    
    // Recursively sort the left and right halves
    left = sortLL(left);
    right = sortLL(right);
    
    // Merge the sorted halves using the mergeTwoSortedLinkedLists function
    return mergeTwoSortedLinkedLists(left, right);
}

// Function to print the linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        // Print the data of the current node
        cout << temp->data << " "; 
        // Move to the next node
        temp = temp->next; 
    }
    cout << endl;
}
//recursion 
Node* merge_2_sorted(Node* head_1,Node* head_2){
    Node* res=NULL;
    if(head_1==NULL){
        return head_2;
    }
    if(head_2==NULL){
        return head_1;
    }
    if(head_1->data <= head_2->data){
        res=head_1;
        res->next=merge_2_sorted(head_1->next,head_2);
    }
    else{
        res=head_2;
        res->next=merge_2_sorted(head_1,head_2->next);
    }
    return res;

}


int main() {
    // Linked List: 3 2 5 4 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLinkedList(head);

    // Sort the linked list
    head = sortLL(head);

    cout << "Sorted Linked List: ";
    printLinkedList(head);

    return 0;
}