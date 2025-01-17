#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
Insertion sort is a sorting algorithm that places an unsorted element at its suitable place in each iteration. 
Insertion sort works similarly as we sort cards in our hand in a card game. We assume that the first card is already sorted then,
 we select an unsorted card.
*/
// there are also rounds
// in every round we fit a card to its right position.
// isme swap nhi sidha shift krke gusa dete h

// space o(1);
//time - o(n^2)-- best-o(n) worst-o(n^2);
//code
 
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
int main(){
    int arr[]={25,11,22,65,7};
    int n=5;
    insertionSort(arr,n);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<"  ";
    }
}