#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// Given an integer array nums, find a contiguous non-empty subarray within the array that has the largest product,
//  and return the product.
// numbers in array can be negative , zero and positive;
// Input: nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

 
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n=nums.size();
        int res1=INT_MIN;
        int product=1;
        for(int i=0;i<n;i++){
            product=product*nums[i];
            if(product>res1){
                res1=product;
            }
            if(product==0){
                product=1;
            }
        }
        //we will check from right side because of zero;
        //understand this example if we only do left t right it will give wrong answer
        //nums = [-1, -2, -3, 0, 4]
        //from left to right we will get ans =4
        //from right to left we will get 6 because of (-3*-2)
        // so we need right to left 
    
        int res2=INT_MIN;
        product=1;
        for(int i=n-1;i>=0;i--){
            product=product*nums[i];
            if(product>res2){
                res2=product;
            }
            if(product==0){
                product=1;
            }
        }
        int res=max(res1,res2);
        return res;
    }
};