/*
A permutation of an array of integers is an arrangement of its members into a sequence or linear order.

For example, for arr = [1,2,3], the following are considered permutations of arr: [1,2,3], [1,3,2], [3,1,2], [2,3,1].

Input: nums = [1,2,3]
Output: [1,3,2]

6 4 1 3 5 2
6 4 1 5 2 3
*/

//approach 1:- get all permutation,sort lexiograph(dictionary) and find the next of given permutation using linear search
// use recursion to get permuation 
//time complexity :- !N*N

//appraoch 2
//o(n)

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size();
        int ind1;
        int ind2;
        for(ind1=n-2;ind1>=0;ind1--){
            if(nums[ind1]<nums[ind1+1]){
                break;
            }
        }
        if(ind1<0){
            reverse(nums.begin(),nums.end());
        }
    
        else{
            for(ind2=n-1;ind2>ind1;ind2--){
                if(nums[ind1]<nums[ind2]){
                    break;
                }
            }
            swap(nums[ind1],nums[ind2]);
            reverse(nums.begin()+ind1+1,nums.end());
            
        }    
    }
};
