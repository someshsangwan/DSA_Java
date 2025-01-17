#include<iostream>
using namespace std;
#include<bits/stdc++.h>
// problem is that - given an array of integers count no. of subarray whose eeleemnt xor is equal to B;

/*Given an array of integers A and an integer B.

Find the total number of subarrays having bitwise XOR of all elements equals to B.
Example Input
Input 1:

 A = [4, 2, 2, 6, 4]
 B = 6         ouput -4;
Input 2:

 A = [5, 6, 7, 8, 9]    output -2;
 B = 5;
 */
int solve(vector<int> &A, int B) {
    int n = A.size();
    unordered_map<int, int> m;
    int count = 0;
    int xorr = 0;
    for(auto i : A) {
        xorr = xorr^i;
        if(xorr == B) count++;
        if(m.find(xorr^B) != m.end()) {
        count += m[xorr^B];
        }
    m[xorr]++;
    }
    return count;
}