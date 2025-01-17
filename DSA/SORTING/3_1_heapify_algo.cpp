//convert array into heap.
//left 2*i
//right 2*i+1    if we consider 1st index as 1;

/*
question - what is heap 
answer- heap is a complete binary tree that comes with a heap order property;

question - what is a complete binary tree
answer -  1) every level is completely filled except leaf node;
        2) Nodes always added from left side;

question -  what is heap order property 
answer  - max heap and min heap

question - what is max heap - in tree root value is always greater than its child;
question - what is min heap - in tree root value is always less than its child;
*/
//heapify algo
// given an array change it into heap;
#include<iostream>
using namespace std;
#include<bits/stdc++.h>
    void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && arr[left]>arr[largest] ){
        largest=left;
    }
    if(right<n && arr[largest]<arr[right]){
        largest=right;
    }
    if(largest !=i){
        swap(arr[largest],arr[i]);
        heapify(arr,n,largest);
    }
}
int main(){
    int arr[6]={54,53,55,52,50};
    //we start index from 1 so left child=2*i, right child=2*i+1
   // if we start from 0th index then left child=2*i+1, right 2*i+2;
   int n=5;
   for(int i=n/2-1;i>=0;i--){
    heapify(arr,n,i);
   }
   
}