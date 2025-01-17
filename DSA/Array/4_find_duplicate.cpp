#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// question is very simple given array of size n is filled with number 1 to n every element appear exactly ones except 1 find that element in o(1) space and o(n) time 
//approach 1 use map  o(n) space and o(n) time complexity;
// optimised approach -o(1) space , o(n) time ;
// ex-  2,5,9,6,9,3,8,9,7,1;
//output -9;
//approach 1_ solw fast pointer;
// approach 2 is very ezz;
int main() {
    int arr[] = {1, 3, 2, 3}; // Input array
    int n = 4; // Size of the array

    for (int i = 0; i < n; i++) {
        int index = abs(arr[i]) - 1; // Calculate the index (1-based to 0-based)

        if (arr[index] < 0) {
            // If the value at the index is negative, it's a duplicate
            cout << abs(arr[i]) << endl;
            return 0;
        }

        // Mark the index as visited by negating the value
        arr[index] = -arr[index];
    }

    // If no duplicate is found
    cout << "No duplicate found" << endl;
    return 0;
}
