#include<iostream>
#include<bits/stdc++.h>
using namespace std;
// given an array and a target value return indices whose  sum value is target;

//Approach_1 ->brute force o(n^2);
//Approach_2 -> sort and 2 pointer o(nlogn)
// Approach_3 -> using 

int mapping_pair_sum(int arr[], int sum, int n)
{
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        int rem = sum - arr[i];
        if (m.find(rem) != m.end())
        {
            // int count = m[rem];
            /*for (int j = 0; j < count; j++)
                cout << "(" << rem << ", "
                     << arr[i] << ")" << endl;*/
            return 1;
        }
        m[arr[i]]++;
    }
    return 0;
}

// if we want to return indices 
    vector<int> twoSum(vector<int>& nums, int target) {
   int n = nums.size();
        unordered_map<int, int> m; // Map to store value -> index mapping
        vector<int> ans;

        // First pass: Populate the map with value -> index
        for (int i = 0; i < n; i++) {
            m[nums[i]] = i;
        }

        // Second pass: Find the two indices
        for (int i = 0; i < n; i++) {
            int rem = target - nums[i]; // Calculate the complement
            if (m.find(rem) != m.end() && m[rem] != i) { // Check if complement exists and is not the same index
                ans.push_back(i);       // Current index
                ans.push_back(m[rem]); // Index of the complement
                break; // Break after finding the first valid pair
            }
        }

        return ans;
        
        
    }