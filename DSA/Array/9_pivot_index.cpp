#include<iostream>
#include<bits/stdc++.h>
using namespace std;
/*
The pivot index is the index where the sum of all the numbers strictly to the left of the index is equal to the sum of all the numbers strictly to
 the index's right.
Input: nums = [1,7,3,6,5,6]
Output: 3
Explanation:
The pivot index is 3.
Left sum = nums[0] + nums[1] + nums[2] = 1 + 7 + 3 = 11
Right sum = nums[4] + nums[5] = 5 + 6 = 11;
*/
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int prefix=0;
        int sum=0;
        for(int i=0;i<n;i++)  sum+=nums[i];
        
        for(int i=0;i<n;i++){ 
            if(prefix==(sum-nums[i]-prefix )){
                return i;
            }
            prefix+=nums[i];
        }
        return -1;
    }