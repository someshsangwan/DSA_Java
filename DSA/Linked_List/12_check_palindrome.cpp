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
    Node* getmiddle(Node* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        Node* slow = head;
        Node* fast = head->next;
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }

    // Function to reverse a linked list
    Node* reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* ford;
        while (curr != NULL) {
            ford = curr->next;
            curr->next = prev;
            prev = curr;
            curr = ford;
        }
        return prev;
    }

    // Function to check if the linked list is a palindrome
    bool isPalindrome(Node* head) {
        // Handle edge cases
        if (head == NULL || head->next == NULL) {
            return true;
        }

        // Step 1: Find the middle of the linked list
        Node* middle = getmiddle(head);

        // Step 2: Reverse the second half of the linked list
        Node* head2 = reverse(middle->next);

        // Step 3: Compare the first half and the reversed second half
        Node* head1 = head;
        Node* temp = head2; // Store head2 to restore the list later
        while (head1 != NULL && head2 != NULL) {
            if (head1->data != head2->data) {
                // Restore the list before returning
                middle->next = reverse(temp);
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }

        // Step 4: Restore the original structure of the list
        middle->next = reverse(temp);

        return true;
    }